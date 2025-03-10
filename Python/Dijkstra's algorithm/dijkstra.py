import random
import time

class Graph:
    def __init__(self, size: int):
        self.adjacent_matrix = [[0] * size for _ in range(size)]
        self.size = size
        self.vertex_data = [''] * size

    def add_edge(self, n: int, m: int, weight: int):
        if 0 <= n < self.size and 0 <= m < self.size:
            self.adjacent_matrix[n][m] = weight
            self.adjacent_matrix[m][n] = weight
    
    def add_vertex_data(self, vertex: int, data: str):
        if 0 <= vertex < self.size:
            self.vertex_data[vertex] = data

    def dijkstra(self, start_vertex_data: int):
        start_vertex = self.vertex_data.index(start_vertex_data)
        distances = [float('inf')] * self.size
        distances[start_vertex] = 0
        visited = [False] * self.size

        for i in range(self.size):
            min_distace = float('inf')
            n = None
            for index in range(self.size):
                if not visited[index] and distances[index] < min_distace:
                    min_distace = distances[index]
                    n = index
                
            if n is None:
                break
            
            visited[n] = True

            for index2 in range(self.size):
                if self.adjacent_matrix[n][index2] != 0 and not visited[index2]:
                    temp = distances[n] + self.adjacent_matrix[n][index2]
                    if temp < distances[index2]:
                        distances[index2] = temp

        return distances
    
def test(data_amount: int):
    g = Graph(data_amount)

    for i in range(data_amount):
        g.add_vertex_data(i, str(i))
    
    for i in range(data_amount):
        for j in range(3): #prideda 3 kelius nuo dabartinio tasko
            g.add_edge(i, random.randint(0, data_amount), random.randint(1, 10)) #prideda kelia prie kito tasko su jo svoriu

    start_time = time.process_time()
    distances = g.dijkstra('0')
    end_time = time.process_time()
    total_time = end_time - start_time

    #print("Algoritmo laikas:", total_time)
    #for i, d in enumerate(distances):
        #print(f"Distance from A to {g.vertex_data[i]}: {d}")
    
    return total_time

average_times = []

for counter in range(20):
    temp_times = []
    for i in range(1,11):
        temp = test(i * 1000)
        temp_times.append(temp)
    average_times.append(temp_times)


for i in range(10):
    temp = []
    for j in range(len(average_times)):
        temp.append(average_times[j][i])
    print(sum(temp) / 20)