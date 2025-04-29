class Graph
    def initialize(@size : Int32)
        @adj_matrix = Array(Array(Int32)).new(@size) { Array(Int32).new(@size, 0) }
        @vertex_data = Array(String).new(@size) { "" }
    end

    def add_edge(u, v, c)
        @adj_matrix[u][v] = c
    end

    def add_vertex_data(vertex, data)
        @vertex_data[vertex] = data if 0 <= vertex && vertex < @size
    end

    def bfs(source_vertex, t, parent)
        visited = Array(Bool).new(@size, false)
        queue = [source_vertex] of Int32
        visited[source_vertex] = true

        until queue.empty?
            u = queue.shift

            @adj_matrix[u].each_with_index do |value, index|
                if !visited[index] && value > 0
                    queue << index
                    visited[index] = true
                    parent[index] = u
                end
            end
        end
        visited[t]
    end

    def edmonds_karp(source, sink)
        parent = Array(Int32).new(@size, -1)
        max_flow = 0

        while bfs(source, sink, parent)
            path_flow = Int32::MAX
            s = sink
            while s != source
                path_flow = Math.min(path_flow, @adj_matrix[parent[s]][s])
                s = parent[s]
            end
            max_flow += path_flow
            v = sink
            while v != source
                u = parent[v]
                @adj_matrix[u][v] -= path_flow
                @adj_matrix[v][u] += path_flow
                v = parent[v]
            end
            path = Array(Int32).new
            v = sink
            while v != source
                path << v
                v = parent[v]
            end
            path << source
            path = path.reverse
            path_names = path.map { |node| @vertex_data[node] }
            puts "Path: #{path_names.join(" -> ")}, Flow: #{path_flow}"
        end
        max_flow
    end
end

g = Graph.new(6)
vertex_names = ["s", "v1", "v2", "v3", "v4", "t"]
vertex_names.each_with_index do |name, index|
    g.add_vertex_data index,name
end

g.add_edge(0, 1, 3)  # s  -> v1, cap: 3
g.add_edge(0, 2, 7)  # s  -> v2, cap: 7
g.add_edge(1, 3, 3)  # v1 -> v3, cap: 3
g.add_edge(1, 4, 4)  # v1 -> v4, cap: 4
g.add_edge(2, 1, 5)  # v2 -> v1, cap: 5
g.add_edge(2, 4, 3)  # v2 -> v4, cap: 3
g.add_edge(3, 4, 3)  # v3 -> v4, cap: 3
g.add_edge(3, 5, 2)  # v3 -> t,  cap: 2
g.add_edge(4, 5, 6)  # v4 -> t,  cap: 6
source = 0
sink = 5
puts "The maximum possible flow is #{g.edmonds_karp(source, sink)}"