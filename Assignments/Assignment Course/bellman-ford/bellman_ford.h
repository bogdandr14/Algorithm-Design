#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

int no_nodes;
struct edge///A structure to represent an edge of the graph
{
    int src;
    int dest;
};

///This  function is used to generate random numbers in a given interval
///@param min_value -int
///@param max_value -int
int random(int min_value, int max_value);

///This function is used to generate the input data for the tests
///@param tests- int
void generator(int tests);

///This function is an implementation to Depth First Search and is used to find
///if between 2 nodes are at least 3 alternative routes
///@param graph -int
///@param source -int
///@param target -int
///@param route -int*
int DFS(int graph[][no_nodes], int source, int target, int route[]);

///This function is used to solve the main problem for each input test
///using my own implementation of Bellman-Ford's algorithm
///@param test_in -FILE*
///@param test_out -FILE*
void BellmanFord(FILE* test_in, FILE* test_out);
#endif // BELLMAN_FORD_H
