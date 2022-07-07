#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "problem_1.h"
#define TESTS_NO 10
#define FILENAME_SIZE 20
int main()
{
    int n, test_iterator, x;
    char temp_name_in[FILENAME_SIZE], temp_name_out[FILENAME_SIZE];
    clock_t start, finish;
    double duration;
    srand(time(0));///use the internal clock of the processor for the seed of random number generator
    for (test_iterator = 1; test_iterator <= TESTS_NO; test_iterator ++)///for generating the input data
    {
        sprintf(temp_name_in, "data\\test_%d.in", test_iterator);
        FILE* test_in = fopen (temp_name_in, "w");
        n = random(1000,100000000);///generate a random number of digits
        fprintf(test_in, "%d", n);///put the generated number in an input file
        fclose(test_in);
    }
    for (test_iterator = 1; test_iterator <= TESTS_NO; test_iterator ++)
    {
        sprintf(temp_name_in, "data\\test_%d.in", test_iterator);
        sprintf(temp_name_out, "data\\test_%d.out", test_iterator);
        FILE* test_in = fopen (temp_name_in, "r");
        FILE* test_out = fopen (temp_name_out, "w");

        fscanf(test_in,"%d",&n);///take the generated number of digits from input file
        start = clock();/// store time before running
        for (x = 0; x < 5000000; x++);///the program was running too fast, giving time 0 on every test, so I had to
        /// put a repetitive structure in order to delay the time, for execution time demonstration
        no_pages(n, test_out);///calculate and print the answer for the current test
        finish = clock();/// store time after measured block ends

        duration = (double)(finish - start) / CLOCKS_PER_SEC;///calculate the duration of the algorithm for the current test
        printf("Duration for Test no.%d: %.3f\n",test_iterator,duration);
        fclose(test_in);
        fclose(test_out);
    }
    return 0;
}
