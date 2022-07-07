class AdjNode: 
	def __init__(self, data): 
		self.vertex = data 
		self.next = None

class Graph: 
	def __init__(self, vertices): 
		self.V = vertices 
		self.graph = [None] * self.V 

	# Function to add an edge in an undirected graph 
	def add_edge(self, src, dest): 
		# Adding the node to the source node 
		node = AdjNode(dest) 
		node.next = self.graph[src] 
		self.graph[src] = node 

		# Adding the source node to the destination as 
		# it is the undirected graph 
		node = AdjNode(src) 
		node.next = self.graph[dest] 
		self.graph[dest] = node 

	# Function to print the graph 
	def print_graph(self): 
		for i in range(self.V): 
			print("Adjacency list of vertex {}\n head".format(i), end="") 
			temp = self.graph[i] 
			while temp: 
				print(" -> {}".format(temp.vertex), end="") 
				temp = temp.next
			print(" \n") 

def route(node):
    self.route = set()
    self.route.add(node)
    self.route.remove(node)

def visited(node):
    self.visited = set()
    self.visited.add(node)
    self.visited.remove(node)

def dfs(Graph, initial, target):
    counter = 0  
    if (initial == target):
        counter = 1;
    route.add(initial)
    for edge in graph.edges[initial] and edge not in route:
        counter = counter + dfs(graph, edge, target)
    return counter

def dijkstra(graph, no_nodes, no_edges, start, target):
    visited = {}
    path = {}
    distance = {vertex: inf for vertex in no_nodes}
    distance[start] = 0
    ok = no_nodes
    while target not in visited and ok: 
        min_node = -1
        min = 99999
        ok = ok-1
        for node in graph[current_node]:
            if node not in visited:
                if (distance[currend_node] +1 < distance[node] and dfs(graph,current_node,node)):
                    distance[node] = distance[current_node] + 1
                    prev[node]=current_node
                if min> distance[node]:
                    min_node = node
                    min = distance[node]
        if min_node is -1:
            break
        current_node = min_node
        visited.add(current_node)
    if ok:
        current_node = target
        j = 0
        while current_node != -1:
            path[j] = current_node
            j=j+1
            current_node = prev[current_node]
        while j>0:
            j=j-1
            print(path[j]and " ")
    else:
        print("the path can not be found")
