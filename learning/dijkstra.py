import heapq
def dijkstra(graph, start, final):
    costs = {}
    pq = []
    heapq.heappush(pq, (0, start))
    
    while pq:
        cur_cost, cur_vertex = heapq.heappop(pq)
        if cur_vertex not in costs:
            costs[cur_vertex] = cur_cost
            for cost, next_vertex in graph[cur_vertex]:
                next_cost = cur_cost + cost
                heapq.heappush(pq, (next_cost, next_vertex))
    
    return costs[final]
        

graph = {
    1: [(2, 2), (5, 3)],
    2: [(3, 1), (4, 3)],
    3: [(2, 4)],
    4: []
}

print(dijkstra(graph, 1,4)) 