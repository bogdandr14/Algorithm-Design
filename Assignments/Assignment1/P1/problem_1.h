/// Created by Draghici Bogdan on 4/15/2019.

#ifndef ASSIGNMENT_1_PROBLEM_1_H
#define ASSIGNMENT_1_PROBLEM_1_H

///This  function is used to generate random numbers
///in a given interval
///@param min_value -int
///@param max_value -int
int random(int min_value, int max_value);

///This function is used to find the number of pages that can
///be created by knowing the number of digits that can be used
///and also write it on an output file
/// @param no_digits -int
/// @param test_out -FILE*
int no_pages(int no_digits, FILE* test_out);

#endif // ASSIGNMENT_1_PROBLEM_1_H

