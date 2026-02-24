
def solution(n, cars, links):
    #먼저 익숙한 그래프 형태로 만들기
    graph = [[]for _ in range(n)]
    for x,y in links:
        graph[x-1].append(y-1)
        graph[y-1].append(x-1)
        
    #하지만, 이 문제에선 방향이 존재해야함 -> 루트가 존재해야함 -> 정해진 건 x -> 내가 임의로 지정하면 됨
    # 루트 0 에서 DFS로 parent와 order 만들기
    root = 0
    stack = [root]
    
    
    
        
        
    

    return