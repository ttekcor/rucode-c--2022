from collections import deque

n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

visited = [False]*(n+1)
components = [0]*(n+1)
component_num = 0

def bfs(start):
    global component_num
    q = deque([start])
    visited[start] = True
    components[start] = component_num
    while q:
        cur = q.popleft()
        for neighbor in graph[cur]:
            if not visited[neighbor]:
                visited[neighbor] = True
                components[neighbor] = component_num
                q.append(neighbor)

for i in range(1, n+1):
    if not visited[i]:
        component_num += 1
        bfs(i)

if m == n-1 and component_num == 1:
    print("YES")
else:
    print("NO")