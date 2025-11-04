import heapq
def dijkstra(graph, start, final):
    costs = {}
    pq = [] # list로 구현해야함.
    heapq.heappush(pq, (0, start))
    
    while pq:
        cur_cost, cur_v = heapq.heappop(pq)
        if cur_v not in costs:
            costs[cur_v] = cur_cost
            for cost, next_v in graph[cur_v]:
                next_cost = cur_cost + cost
                heapq.heappush(pq, (next_cost, next_v))
    return costs[final-1]

graph = {
    1: [(2, 2), (5, 3)],
    2: [(3, 1), (4, 3)],
    3: [(4, 2)],
    4: []
}

print(dijkstra(graph, 1,4)) #5