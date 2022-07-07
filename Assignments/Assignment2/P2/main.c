#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "P2.h"
#define TESTS_NO 10
#define FILENAME_SIZE 20
int n;
int main()
{
    int n, test_iterator, x;
    char temp_name_in[FILENAME_SIZE], temp_name_out[FILENAME_SIZE];
    clock_t start, finish;
    double duration;
    srand(time(0));///use the internal clock of the processor for the seed of random number generator
    generator(TESTS_NO);
    for (test_iterator = 1; test_iterator <= TESTS_NO; test_iterator ++)
    {
        sprintf(temp_name_in, "data\\test_%d.in", test_iterator);
        sprintf(temp_name_out, "data\\test_%d.out", test_iterator);
        FILE* test_in = fopen (temp_name_in, "r");
        FILE* test_out = fopen (temp_name_out, "w");
        start = clock();/// store time before running
        int n, r, i, x, y;
        fscanf(test_in,"%d%d", &n, &r);
        struct Graph *G = createGraph(n);
        for(i = 1; i <= r; i++)
        {
            fscanf(test_in, "%d%d", &x, &y);
            addEdge(G, x, y);
        }
        towers(G, test_out);///calculate and print the answer for the current test
        finish = clock();/// store time after measured block ends
        duration = (double)(finish - start) / CLOCKS_PER_SEC;///calculate the duration of the algorithm for the current test
        printf("Duration for Test no.%d: %.3f\n", test_iterator,duration);
        fclose(test_in);
        fclose(test_out);
    }
	return 0;
}
