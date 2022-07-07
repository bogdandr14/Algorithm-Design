#ifndef P2_H
#define P2_H

struct AdjListNode/// A structure to represent an adjacency list node
{
	int dest;
	struct AdjListNode* next;
};
struct AdjList/// A structure to represent an adjacency list
{
	struct AdjListNode *head;
};
struct Graph/// A structure to represent a graph. A graph is an array of adjacency lists. Size of array will be V (number of vertexes in graph)
{
	int V;
	struct AdjList* array;
};
struct queue{/// A structure to represent a queue.
    int info;
    struct queue *next;
};
///This  function is used to generate random numbers in a given interval
///@param min_value -int
///@param max_value -int
int random(int min_value, int max_value);

///This function is used to generate the input data for the tests
///@param tests- int
void generator(int tests);

///This function adds a new element to the end of the queue
///@param head -struct queue*
///@param new_value -int
void queue_push(struct queue *head, int new_value);

///This function is used to eliminate the first element of the queue and return its value
///@param head -struct queue*
int queue_pop(struct queue *head);

///This function is used to create a graph with no_nodes nodes
///@param no_nodes -int
struct Graph* createGraph(int no_nodes);

///This function is used to add a new edge from node scr to node dest to the graph
///@param graph -struct Graph*
///@param src -int
///@param dest -int
void addEdge(struct Graph* graph, int src, int dest);

///This function is used to insert a new node in a adjacency list of a specific node
///@param info -int
struct AdjListNode* newAdjListNode(int info);

///This function is used to assign the towers as attack or defense and return if it can or can not do so
///@param G - struct Graph*
///@param test_out - FILE*
void towers(struct Graph *G, FILE* test_out);
#endif // P2_H
