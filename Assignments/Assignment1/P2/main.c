#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "problem_2.h"
#define TESTS_NO 10

int main()
{
    int n, pair_iterator, test_iterator;
    char temp_name_in[20], temp_name_out[20];
    clock_t start, finish;
    double duration;
    srand (time(0));///seed the random algorithm with the time of the processor's internal clock
    generator(TESTS_NO);///generate the input data for the tests
    for (test_iterator = 1; test_iterator <= TESTS_NO; test_iterator++)
    {
        sprintf(temp_name_in, "data\\test_%d.in", test_iterator);
        sprintf(temp_name_out, "data\\test_%d.out", test_iterator);
        FILE* test_in = fopen (temp_name_in, "r");
        FILE* test_out = fopen (temp_name_out, "w");

        fscanf(test_in,"%d",&n);///receive the generated number of pairs
        double *v = calloc(2 * n + 1, sizeof(double));
        for(pair_iterator = 1 ; pair_iterator <= 2 * n; pair_iterator++)
        {
            fscanf(test_in,"%lf",&v[pair_iterator]);///receive the values for the vector
        }
        start = clock();/// store time before running
        merge_sort(v, 1, 2 * n);///sort the vector
        max_sum(n, v, test_out);///call the function to solve the problem
        finish = clock();///store time after running
        duration = (double)(finish - start)/CLOCKS_PER_SEC;
        printf("Test no.%d was executed in %.3f seconds\n",test_iterator,duration);
        free(v);
        fclose(test_in);
        fclose(test_out);
    }
    return 0;
}
