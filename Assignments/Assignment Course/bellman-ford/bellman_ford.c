#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bellman_ford.h"
int no_nodes, no_edges, start, finish;
int random(int min_value, int max_value){///generates a number in a given range
    int counter = max_value - min_value, number = 0;
    while (counter != 0) {///this will repeat until the number has a chance to get the max value of range
        number += number * RAND_MAX + rand();
        counter /= RAND_MAX;
    }
    return number % (max_value - min_value + 1) + min_value;///creates the number in the given range
}
void generator(int tests)///generates the input data for a given test
{
    int test_iterator, iterator, source, destination;
    char temp_name_in[20];
    for (test_iterator = 1; test_iterator <= tests; test_iterator++)
    {
        sprintf(temp_name_in, "data\\test_%d.in", test_iterator);
        FILE* test_in = fopen (temp_name_in, "w");
        no_nodes = random(100, 700);///generates the number of nodes of the graph
        no_edges = random(1000, 1000000)%(no_nodes*(int)sqrt(no_nodes));///generates the number of edges of the graph
        start = random(1000, 100000) % no_nodes;///generates the starting node
        finish = random(1000, 100000) % no_nodes;///generates the destination node
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
int DFS(int graph[][no_nodes], int source, int target, int route[])
{
    int j, counter = 0;
    if(source == target)///if we find a route, return true
        return 1;
    route[source] = 1;
	for(j = 0; j < no_nodes; j++)
        if(!route[j] && graph[source][j] == 1)///if the node was not visited, we search for a route from this point forward
            counter += DFS(graph, j, target, route);///increment counter with any route found
    return counter;///return the number of alternative routes found
}
void BellmanFord(FILE* test_in, FILE* test_out)
{
    fscanf(test_in,"%d%d%d%d", &no_nodes, &no_edges, &start, &finish);
    struct edge *edges = (struct edge*) calloc(no_edges, sizeof(struct edge));  /// Every edge has two values (u, v) where the edge is from vertex u to v.
    int i, j, k, graph[no_nodes][no_nodes], distance[no_nodes], prev[no_nodes], route[no_nodes];
    for(i = 0; i < no_edges; i++)
    {
        fscanf(test_in,"%d%d", &edges[i].src, &edges[i].dest);
        graph[edges[i].src][edges[i].dest] = graph[edges[i].dest][edges[i].src] = 1;
    }
	for (i = 0; i < no_nodes; i++)///initialize distance of all vertexes as a very big number
		distance[i] = no_nodes;
	distance[start] = 0;///initialize the distance from the starting point with 0
	///a simple shortest path from start to any other vertex can have at-most no_nodes - 1 edges
	for (i = 0; i < no_nodes; i++)///the route was maximum no_nodes-1 edges, so if there is a solution, it will be found in maximum no_nodes-1 steps
		for (j = 0; j < no_edges; j++)
			if (distance[edges[j].src] + 1< distance[edges[j].dest])///compare to see if there is a shorter distance for node edges[j].src
			{
                for(k = 0; k < no_nodes; k++)///initialize the visited routes for the DFS function
                    route[k] = 0;
                if( DFS(graph, edges[j].src, edges[j].dest,route) >= 3)///find if there are at least 2 other alternative routes to point edges[j].dest
                {
                    distance[edges[j].dest] = distance[edges[j].src] + 1;///reinitialize the distance to the node edges[j].dest
                    prev[edges[j].dest] = edges[j].src;///memorize edges[j].src as the previous to edges[j].dest for the shortest path
                }
			}
	if(distance[finish] == no_nodes)///if there is not a route that fulfill the conditions, print that
        fprintf(test_out,"The destination can't be reached with the given input");
    else///in contrary, print the answer
    {
        int current_node = finish;
        int path[distance[finish] + 1];
        path[distance[finish]] = finish;
        for(i = distance[finish]-1;i >= 0; i--)///creates the path from the destination to the beginning
        {
            path[i] = prev[current_node];
            current_node = prev[current_node];
        }
        fprintf(test_out, "Vertex distance from starting point %d to destination %d is %d\nThe path is: ", start, finish, distance[finish]);
        for(i = 0; i <= distance[finish]; i++)///print the nodes it goes through
            fprintf(test_out, "%d ", path[i]);
    }
}
