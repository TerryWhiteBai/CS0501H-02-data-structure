from typing import List

n = 10
edge = [(0,1),(1,2),(2,0),(1,3),(3,4),(4,5),(5,2),(2,6),(6,7),(6,8)]

time = 0  # time stamp
dfs = [-1] * n #the first time a vertex is visited, record the time stamp
low = [-1] * n # visted neighbor(include itself) with lowest dfs, to judge whether it's a bridge
bridge:List[tuple[int,int]] = []
graph = {i:[] for i in range(n)} 

for u, v in edge:
    graph[v].append(u)
    graph[u].append(v)
    
def targan_bridge(u:int, parent:int = -1): #parent记录父节点，不重复走
    r"""
    seems to be a directed graph

    every back edge connects v and its ancestor
    dfs traverse
    in every layer: forward to u and find bridges connecting u and it's children
    """
    global time
    if dfs[u] == -1:
        time = time + 1
        low[u] = dfs[u] = time

        for v in graph[u]:
            if v == parent: continue #跳过父节点

            if dfs[v] != -1: # back edge
                low[u] = min(low[v], low[u])

            else: # forward edge
                targan_bridge(v, u) 
                low[u] = min(low[v], low[u])

            if low[v] > dfs[u]: # we show that there are no edges connect v's subtree to u's ancestor, then (u,v) is a bridege
                bridge.append((u,v))


def main():
    for i in range(n):
        targan_bridge(i)
    print(bridge)

if __name__ == '__main__':
    main()


