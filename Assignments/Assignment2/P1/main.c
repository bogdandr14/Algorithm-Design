#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NO_TESTS 10
#include "P1.h"
int main()
{
    int no_children, test_iterator, k, iterator, new_value;
    char temp_name_in[20], temp_name_out[20];
    clock_t start, finish;
    double duration;
    srand(time(0));///use the internal clock of the processor for the seed of random number generator
    generator(NO_TESTS);
    for (test_iterator = 1; test_iterator <= NO_TESTS; test_iterator ++)
    {
        sprintf(temp_name_in, "data\\test_%d.in", test_iterator);
        sprintf(temp_name_out, "data\\test_%d.out", test_iterator);
        FILE* test_in = fopen (temp_name_in, "r");
        FILE* test_out = fopen (temp_name_out, "w");

        start = clock();/// store time before running
        fscanf(test_in,"%d", &no_children);///read the number of children
        fscanf(test_in, "%d", &k);///read the number that must be counted in order to remove a child
        struct doubly_node *head = malloc(sizeof(struct doubly_node));
        struct doubly_node *tail = malloc(sizeof(struct doubly_node));
        head -> previous = NULL;///initialization foe the doubly_linked list
        head -> next = tail;
        head -> info = no_children;
        tail -> previous = head;
        tail -> next = NULL;
        for(iterator = 1; iterator <= no_children; iterator++)///create the doubly linked list
        {
            fscanf(test_in, "%d", &new_value);///read the next children
            dl_push_element_end(head, tail, new_value);///put the children in the list
        }
        tail -> previous -> next = head -> next;///transform the doubly linked structure in a circular list
        head -> next -> previous = tail -> previous;
        ala_bala_portocala(head, tail, k, test_out);///calculate the order in which the children are removed and print them in an output file
        finish = clock();/// store time after measured block ends

        duration = (double)(finish - start) / CLOCKS_PER_SEC;///calculate the duration of the algorithm for the current test
        printf("Duration for Test no.%d: %.3f\n",test_iterator,duration);
        fclose(test_in);
        fclose(test_out);
    }
    return 0;
}
