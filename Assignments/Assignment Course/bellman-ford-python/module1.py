def dfs(Graph, initial, target):
    counter = 0  
    if (initial == target):
        counter = 1
    route[initial] = 1
    for edge in graph[initial] and edge not in route:
        counter = counter + dfs(graph, edge, target)
    return counter

def bellman_ford(graph, no_nodes, no_edges, start, finish):
    i = 0
    for i in no_edges:
        x = f.readline()
        y = f.readline()
        graph[x][y] = 1 
        graph[y][x] = 1
        edges.src[i] = x
        edges.dest[i] = y
    for i in no_nodes:
        distance[i] = 999
        prev[i] = -1
    distance[start] = 0
    i = 0
    while i < no_nodes:
        j = 0
        while j < no_edges:
            if (distance[edges.src[i]] + 1 < distance[edges.dest[i]]):
                k = 0
                while k < no_nodes:
                    route[k] = 0
                    k = k + 1
                if (dfs(graph, edges.src, edges.dest, route) >= 3):
                    distance[edges.dest[j]] = distance[edges.src[j]] + 1
                    prev[edges.dest[j]] = edges.src[j]
            j = j + 1
        i = i + 1
    if distance[finish] == no_nodes:
        print("the destination can not be reached")
    else:
        current_node = finish
        path[distance[finish]] = finish
        i = distance[finish] -1
        while i >= 0:
            path[i] = prev[current_node]
            current_node = prev[current_node]
            i = i - 1
        i = 0
        while i <= distance[finish]:
            print(path[i])
