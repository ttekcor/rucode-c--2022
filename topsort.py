# Считываем входные данные
n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
in_degree = [0]*(n+1) # массив для хранения входящих степеней вершин
for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    in_degree[b] += 1

# Создаем очередь и добавляем в нее вершины с нулевой входящей степенью
q = []
for i in range(1, n+1):
    if in_degree[i] == 0:
        q.append(i)

# Проходим по очереди и удаляем вершины, уменьшая входящие степени их соседей
result = []
while q:
    cur = q.pop(0)
    result.append(cur)
    for neighbor in graph[cur]:
        in_degree[neighbor] -= 1
        if in_degree[neighbor] == 0:
            q.append(neighbor)

# Проверяем, удалось ли отсортировать все вершины
if len(result) != n:
    print(-1)
else:
    print(*result) # выводим результат