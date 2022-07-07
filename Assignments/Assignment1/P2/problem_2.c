#include <stdio.h>
#include <stdlib.h>

double random(int min_value, int max_value){///generates a number in a given range
    int counter = max_value - min_value,number=0;
    while (counter != 0) {///this will repeat until the number has a chance to get the max value of range
        number += number * RAND_MAX + rand();
        counter /= RAND_MAX;
    }
    double real_number=(double)(number % (max_value - min_value + 1))/RAND_MAX*rand();///creates a real value for the number in the given range
    return real_number + min_value;
}
void generator(int tests)///generates the input data for a given test
{
    int test_iterator, no_pairs,iterator;
    char temp_name_in[20];
    for (test_iterator = 1; test_iterator <= tests; test_iterator ++)
    {
        sprintf(temp_name_in, "data\\test_%d.in", test_iterator);
        FILE* test_in = fopen (temp_name_in, "w");
        no_pairs=(int)random(500,50000);///generates the number of pairs
        fprintf(test_in,"%d\n",no_pairs);///print the generated number of pairs
        for(iterator = 0 ;iterator < 2 * no_pairs; iterator++)
        {
            fprintf(test_in,"%lf ",random(0,100000000));///generates writes a number in a given range in an input file
        }
        fclose(test_in);
    }
}
void merge_left_right(double *vector, int left, int middle, int right)///
{
    int it_left, it_right, it_merge, no_elem_left = middle - left + 1, no_elem_right = right - middle;
    double *vector_left = calloc(no_elem_left, sizeof(double));
    double *vector_right = calloc(no_elem_right, sizeof(double));
    for (it_left = 0; it_left < no_elem_left; it_left++){///copies in vector_left the values from left to mid, that must be assigned to the sorted vector
            vector_left[it_left] = vector[left + it_left];
    }
    for (it_right = 0; it_right < no_elem_right; it_right++){///copies in vector_right the values from mid+1 to right, that must be assigned to the sorted vector
        vector_right[it_right] = vector[middle + 1 + it_right];
    }
    it_left = it_right = 0;
    it_merge = left;
    while ((it_left < no_elem_left) && (it_right < no_elem_right)){///verify which from the first elements of the 2 vectors is smaller, in order to write it in the sorted vector
        vector[it_merge++] = (vector_left[it_left] < vector_right[it_right]) ? vector_left[it_left++] : vector_right[it_right++];
    }
    while (it_left < no_elem_left){///one of the vector will remain with elements that were not written in the sorted vector
            vector[it_merge++] = vector_left[it_left++];
    }
    while (it_right < no_elem_right){
        vector[it_merge++] = vector_right[it_right++];
    }
    free(vector_left);
    free(vector_right);
}
void merge_sort(double *vector, int left, int right){///sorts the vector using backtracking and divide and conquer methods
    int mid;
    if (left != right){
        mid = (left + right) / 2;
        merge_sort(vector, left, mid);///calls itself till the range of elements is 1
        merge_sort(vector, mid + 1, right);
        merge_left_right(vector, left, mid, right);///assembly the sorted parts of the vector, starting from 2 vectors with 1 element each
    }
}
void max_sum(int no_pairs, double *vector, FILE* test_out)
{
    int iterator;
    double sum, max_value = -1;
    for(iterator = 1 ; iterator <= no_pairs; iterator++ )///for creating the no_pairs pairs of numbers
    {
        fprintf(test_out,"(%lf,%lf),\n",*(vector+iterator),*(vector+2*no_pairs-iterator+1));///writes in an output file the pairs
        sum = vector [iterator] + vector [2 * no_pairs - iterator + 1];///calculates the sum of the pairs
        max_value = (sum > max_value) ? sum : max_value;///verifies if the sum is bigger than the max and attributes sum to max in affirmative case
    }
    fprintf(test_out,"\nThe minimum max sum that can be created is %lf",max_value);///writes the minimum of the maximum sum that can be created using the pairs of numbers
}
