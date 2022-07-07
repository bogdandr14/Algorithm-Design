/// Created by Draghici Bogdan on 4/15/2019.

#ifndef ASSIGNMENT_1_PROBLEM_2_H
#define ASSIGNMENT_1_PROBLEM_2_H

///This function is used to generate
///bigger random numbers
///@param min_value - int*
///@param max_value - int*
double random(int min_value, int max_value);

///This function is used to generate a
///specific number of input data tests
///@param tests- int
void generator(int tests);

///Merge Sort algorithm for integer array
///@param vector - double*
///@param left - int
///@param right - int
void merge_sort(double *vector, int left, int right);

///This function is used in Merge Sort algorithm
///@param vector - double*
///@param left - int
///@param middle -int
///@param right - int
void merge_left_right(double *vector, int left, int middle, int right);

///This function is used to find the maximum sum
///from the sums of pairs witch have the overall smallest sums
///@param no_pairs - int
///@param vector - double*
void max_sum(int no_pairs, double *vector, FILE* test_out);

#endif // ASSIGNMENT_1_PROBLEM_2_H
