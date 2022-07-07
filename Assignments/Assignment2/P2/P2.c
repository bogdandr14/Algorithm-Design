#include <stdio.h>
#include <stdlib.h>
#include "P2.h"
int random(int min_value, int max_value){///generates a number in a given range
    int counter = max_value - min_value, number = 0;
    while (counter != 0) {///this will repeat until the number has a chance to get the max value of range
        number += number * RAND_MAX + rand();
        counter /= RAND_MAX;
    }
    return number % (max_value - min_value + 1) + min_value;///creates the number in the given range
}
struct AdjListNode* newAdjListNode(int info)/// an utility function to create a new adjacency list node
{
	struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
	newNode->dest = info;
	newNode->next = NULL;
	return newNode;
}
struct Graph* createGraph(int no_nodes)/// an utility function that creates a graph of V vertices
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->V = no_nodes;
	graph->array = (struct AdjList*) malloc(no_nodes * sizeof(struct AdjList));/// create an array of adjacency lists, size of array will be V
	int i;
	for (i = 0; i < no_nodes; ++i)/// initialize each adjacency list as empty by making head as NULL
		graph->array[i].head = NULL;
	return graph;
}
void addEdge(struct Graph* graph, int src, int dest)/// adds an edge to an undirected graph
{
	/// add an edge from src to dest and a new node is added to the adjacency list of src
	struct AdjListNode* newNode = newAdjListNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;
	///graph is undirected, so we add an edge from dest to src also
	newNode = newAdjListNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}
int queue_pop(struct queue *Q){///pops the first element of the queue
    struct queue *poped_element = Q->next;
    int aux;
    aux=poped_element->info;
    Q->info++;
    Q->next = poped_element->next;
    free(poped_element);
    return aux;
}
void queue_push(struct queue *Q ,int new_element_value){///adds a new element to the end of the queue
    struct queue *new_element = malloc(sizeof(struct queue));
    struct queue *last_element, *iterator = Q;
    while (iterator->next != NULL) {
        iterator = iterator->next;
    }
    last_element = iterator;
    last_element->next = new_element;
    new_element->info = new_element_value;
    new_element->next = NULL;
}
void generator(int tests)///generates the input data for a given test
{
    int test_iterator, number, iterator, no_tunnels, tunnel1, tunnel2;
    char temp_name_in[20];
    for (test_iterator = 1; test_iterator <= tests; test_iterator++)
    {
        sprintf(temp_name_in, "data\\test_%d.in", test_iterator);
        FILE* test_in = fopen (temp_name_in, "w");
        number = random(1000, 100000);
        no_tunnels = random(1000, 10000000) % (number * number);
        fprintf(test_in, "%d\n%d\n", number,no_tunnels);
        for(iterator = 0 ;iterator < no_tunnels; iterator++)
        {
            tunnel1 = random(0,100000) % number;///creates the number of the tower from which the tunnel starts
            do{
                tunnel2 = random(0,100000) % number;///creates the number of the tower from which the tunnel ends
            }while(tunnel1 == tunnel2);
            fprintf(test_in, "%d %d\n", tunnel1, tunnel2);///writes in an input file the pair of numbers that creates the tunnel
        }
        fclose(test_in);
    }
}
void towers(struct Graph* G, FILE* test_out)
{
	///create an array to store the types assigned to all towers: the value 1 is used to indicate defense tower and value 0 indicates attack tower
	int tower_type[G->V], ok = 1;
	for (int i = 0; i < G->V; i++)///initialize all towers with the value -1 of tower_type[i] is used to indicate that no type is assigned to tower yet
		tower_type[i] = -1;
	struct queue *Q = malloc(sizeof(struct queue));/// create a queue (FIFO) of vertex numbers and enqueue source vertex for BFS traversal
	Q->next = NULL;
	int u, v, i;
	for(i = 0; i < G->V; i++)///this will repeat till all nodes are verified and assigned as attack or defense, no matter if they have or not edges
    {
        if(tower_type[i] == -1)
            tower_type[i] = 1;///if we have not visited the subgraph containing the node i, we automatically assign it as defense
        queue_push(Q,i);///and add it to the queue
        while (Q->next != NULL && ok)/// Run while there are towers in queue (Similar to BFS)
        {
            u = queue_pop(Q);/// dequeue a vertex from queue
            struct AdjListNode *v = G->array[u].head;///assign a pointer to the list of adjacent node u
            while(v){///this structure will repeat till all the adjacent nodes are verified
                if (tower_type[v->dest] == -1)/// An edge from tower u to tower v->dest exists and tower v->dest is not assigned as attack or defense
                {
                    tower_type[v->dest] = 1 - tower_type[u];/// Assign alternate type of tower to this adjacent v->dest of u
                    queue_push(Q, v->dest);///enqueue the tower v->dest
                }
                else if (tower_type[v->dest] == tower_type[u])/// A tunnel from u to v->dest exists and destination v->dest is the same type as u
                    {
                        ok = 0;
                        break;
                    }
                v = v->next;///go to the next adjacent node of u in the list
            }
        }
    }
    if(ok)
            fprintf(test_out, "The towers of attack and defense are successfully created");
        else
            fprintf(test_out, "The towers can not be created with the given tunnels");
}

