
/// Created by Draghici Bogdan on 5/09/2019.

#ifndef ASSIGNMENT_2_PROBLEM_1_H
#define ASSIGNMENT_2_PROBLEM_1_H
struct doubly_node{
    int info;
    struct doubly_node *next;
    struct doubly_node *previous;
};
struct g_node{
    int info;
    struct doubly_node *next;
};
///This  function is used to generate random numbers in a given interval
///@param min_value -int
///@param max_value -int
int random(int min_value, int max_value);

///This function is used to generate the input data for the tests
///@param tests- int
void generator(int tests);

///This function is used to add an element at the end of the doubly linked list
///@param head -doubly_node*
///@param tail -doubly_node*
///@param new_element_value -int
void dl_push_element_end(struct doubly_node *head ,struct doubly_node *tail ,int new_element_value);

///The function is used solve the problem by printing in an output file
///the children in the order in which they are eliminated from the list
///@param head -doubly_node*
///@param tail -doubly_node*
///@param k -int
///@param file_out -FILE*
void ala_bala_portocala(struct doubly_node *head,struct doubly_node *tail, int k, FILE* file_out);

#endif //ASSIGNMENT_2_PROBLEM_1_H
