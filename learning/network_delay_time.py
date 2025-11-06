import heapq
from collections import defaultdict
def network_delay_time(times, n, k):
    graph = defaultdict(list)
    for time in times:
        graph[time[0]].append((time[2], time[1]))
    
    costs = {}
    pq = []
    heapq.heappush(pq,(0,k))
    
    while pq:
        cur_cost , cur_node = heapq.heappop(pq)
        if cur_node not in costs:
            costs[cur_node] = cur_cost
            for cost, next_node in graph[cur_node]:
                next_cost = cur_cost + cost
                heapq.heappush(pq, (next_cost, next_node))
                
    for node in range(1, n+1):
        if node not in costs:
            return -1
    
    return max(costs.values())


times = [[2,1,2],[2,3,5],[2,4,1],[4,3,3]]
print(network_delay_time(times, 4,2))