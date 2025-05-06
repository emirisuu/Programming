require "benchmark"

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

def test_algorithm(data_amount : Int32)
    g = Graph.new(data_amount)
    (0...data_amount).each do |index|
        g.add_vertex_data index, index.to_s
    end

    (0...data_amount - 1).each do |index|
        3.times do
            g.add_edge index, Random.rand(data_amount), Random.rand 1..10
        end
    end

    sink = [5, data_amount - 1].min #Use 5 or the last vertex if data_amount is less than 5
    total_time = Benchmark.measure {g.edmonds_karp 0, sink}
    total_time
end

average_times = Array(Float64).new

(1..11).each do |index|
    run_total_time = 0

    20.times do
        run_total_time += test_algorithm(index * 1000).total
    end
    average_times << run_total_time / 20
end

average_times.each_with_index do |value, index|
    puts "Size #{index * 1000}, Time taken #{value}s"
end