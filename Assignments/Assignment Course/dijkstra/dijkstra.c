#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dijkstra.h"

struct AdjListNode* newAdjListNode(int info)/// an utility function to create a new adjacency list node
{
	struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
	newNode->data = info;
	newNode->next = NULL;
	return newNode;
}
void AddRoute(struct Graph* graph, int src, int dest)/// adds an edge to an undirected graph
{
	struct AdjListNode* newNode = newAdjListNode(dest);/// add an edge from src to dest and a new node is added to the adjacency list of src
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	newNode = newAdjListNode(src);///graph is undirected, so we add an edge from dest to src also
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}
struct Graph* CreateGraph(int no_nodes)/// an utility function that creates a graph of V vertices
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->array = (struct AdjList*) malloc(no_nodes * sizeof(struct AdjList));/// create an array of adjacency lists, size of array will be V
	int i;
	for (i = 0; i < no_nodes; ++i)/// initialize each adjacency list as empty by making head as NULL
		graph->array[i].head = NULL;
	return graph;
}
int random(int min_value, int max_value)///generates a number in a given range
{
    int counter = max_value - min_value, number = 0;
    while (counter != 0) {///this will repeat until the number has a chance to get the max value of range
        number += number * RAND_MAX + rand();
        counter /= RAND_MAX;
    }
    return number % (max_value - min_value + 1) + min_value;///creates the number in the given range
}
void generator(int tests)///generates the input data for a given test
{
    int test_iterator, iterator, no_edges, no_nodes, start, finish, source, destination;
    char temp_name_in[20];
    for (test_iterator = 1; test_iterator <= tests; test_iterator++)
    {
        sprintf(temp_name_in, "data\\test_%d.in", test_iterator);
        FILE* test_in = fopen (temp_name_in, "w");
        no_nodes = random(100, 5000);///generates the number of nodes of the graph
        no_edges = random(1000, 1000000)%(no_nodes*(int)sqrt(no_nodes));///generates the number of edges of the graph
        start = random(1000, 100000) % no_nodes;///generates the starting node
        do{
                finish = random(1000, 100000) % no_nodes;///generates the destination node
            }while(start == finish);
        fprintf(test_in, "%d %d %d %d\n", no_nodes, no_edges, start, finish);
        for(iterator = 0 ;iterator < no_edges; iterator++)
        {
            source = random(0,100000) % no_nodes;///creates the node from which an edge begins
            do{
                destination = random(0,100000) % no_nodes;///creates the node where the edge ends
            }while(source == destination);
            fprintf(test_in, "%d %d\n", source, destination);///writes in an input file the pair of nodes that creates an edge
        }
        fclose(test_in);
    }
}
int DFS(struct Graph *graph, int source, int target, int route[])
{
    int j, counter = 0;
    if(source == target)///if we find a route, return true
        return 1;
    route[source] = 1;
    struct AdjListNode *aux = graph->array[source].head;///initialize aux with the first element in the adjacency list
	while(aux)
    {
        if(!route[aux->data])///if the node was not visited, we search for a route from this point forward
            counter += DFS(graph, aux->data, target, route);///increment counter with any route found
        aux = aux->next;
    }
    return counter;///return the number of alternative routes found
}
int Dijsktra(FILE* test_in, FILE* test_out)
{
    int no_edges, no_nodes, source, target, i, m, min, x, y, current_node, ok;
    fscanf(test_in,"%d%d%d%d", &no_nodes, &no_edges, &source, &target);
    struct Graph *graph = CreateGraph(no_nodes);///create the graph
    for(i = 0; i < no_edges; i++)///add the edges of the graph
    {
        fscanf(test_in,"%d%d", &x, &y);
        AddRoute(graph, x, y);
    }
    int dist[no_nodes], prev[no_nodes], visited[no_nodes], path[no_nodes], route[no_nodes];
    for(i = 0; i < no_nodes; i++)///initialize the distances, the nodes visited, the path and the previous of a node
    {
        dist[i] = no_nodes;
        visited[i]= 0;
        path[i] = 0;
        prev[i] = -1;
    }
    current_node = source;///the first node takes the value of the starting point
    visited[source] = 1;///also make it visited
    dist[source] = 0;///and the distance to reach it 0
    ok = no_nodes;///a route has maximum no_nodes-1 edges, so we use the counter ok to exit the repetitive structure in case there is no route
    while(!visited[target] && ok)
    {
        min = no_nodes;///initialize the min with the maximum path+1
        ok--;///decrement the counter
        m = -1;
        struct AdjListNode *aux = graph->array[current_node].head;///aux taxes the first element of the adjacency list of current_node
        while(aux)///this will continue till all nodes in the adjacency list are visited
        {
            if(visited[aux->data] == 0)
            {
                for(i = 0; i < no_nodes; i++)
                    route[i] = 0;///reinitialize the visited routes for the function DFS
                if(dist[current_node] + 1 < dist[aux->data] && DFS(graph, current_node, aux->data, route) >= 3)///compare if the route is
                {///shorter than the previous found and see if there are at least 2 alternative routes to reach the node from aux->data
                    dist[aux->data] = dist[current_node] + 1;///add the new distance to reach the node from aux->data
                    prev[aux->data] = current_node;///memorize the current node as the previous to aux->data for the shortest path
                }
                if(min>dist[aux->data])
                {
                    min = dist[aux->data];///store the minimum distance found
                    m = aux->data;///and the node for which it was found
                }
            }
            aux = aux->next;///goes to the next node in the adjacency list
        }
        if(m == -1)
        {
            ok = 0;///if there are no other nodes that fulfill the condition, the algorithm ends
            break;
        }
        current_node = m;///takes the value of the next node
        visited[current_node] = 1;///and mark it as visited
    }
    if(ok)///if there was found a route that fulfill the conditions, print the answer
    {
        current_node = target;
        i = 0;
        while(current_node != -1)
        {
            path[i++] = current_node;///creates the path from the destination to the beginning
            current_node = prev[current_node];
        }
        fprintf(test_out,"The shortest path has %d edges\nThe path is: ", dist[target]);///print the number of edges of the path
        while(i)///print the nodes it goes through
            fprintf(test_out, "%d ",path[--i]);
    }
    else///in contrary, print that there are no paths that fulfill the conditions
        fprintf(test_out,"The path can not be found with the given input");
}
