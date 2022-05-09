# DFS algorithm in Python
# DFS algorithm
def dfsearch(graph, starting, visited=None):
    if visited is None:
        visited = set()
    visited.add(starting)

    print(starting)

    for next in graph[starting] - visited:
        dfsearch(graph, next, visited)
    return visited


graph = {'0': set(['1', '2']),
         '1': set(['0', '3', '4']),
         '2': set(['0']),
         '3': set(['1']),
         '4': set(['2', '3'])}

dfsearch(graph, '0')