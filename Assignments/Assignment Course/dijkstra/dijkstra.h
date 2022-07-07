#ifndef DIJKSTRA_H
#define DIJKSTRA_H

struct AdjListNode/// A structure to represent a node in an adjacency list
{
	int data;
	struct AdjListNode* next;
};
struct AdjList/// A structure to represent an adjacency list
{
	struct AdjListNode *head;
};
struct Graph/// A structure to represent a graph. A graph is an array of adjacency lists.
{
	struct AdjList* array;
};
///This function is used to create and allocate memory for a graph with a given number of nodes
///@param no_nodes - int
struct Graph* CreateGraph(int no_nodes);

///This function is used to create and allocate memory for a new element in an adjacency list
///@param info -int
struct AdjListNode* newAdjListNode(int info);

///This function is used to add two nodes in the adjacency list of each other
///@param graph - struct Graph*
///@param src -int
///@param dest -int
void AddRoute(struct Graph* graph, int src, int dest);

///This  function is used to generate random numbers in a given interval
///@param min_value -int
///@param max_value -int
int random(int min_value, int max_value);

///This function is used to generate the input data for the tests
///@param tests- int
void generator(int tests);

///This function is an implementation to Depth First Search and is used to find
///if between 2 nodes are at least 3 alternative routes
///@param graph -struct Graph*
///@param source -int
///@param target -int
///@param route -int*
int DFS(struct Graph *graph, int source, int target, int route[]);

///This function is used to solve the main problem for each input test
/// using my own implementation of Dijkstra's algorithm
///@param test_in -FILE*
///@param test_out -FILE*
int Dijsktra(FILE* test_in, FILE* test_out);

#endif // DIJKSTRA_H
