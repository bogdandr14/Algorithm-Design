#include <stdio.h>
#include <stdlib.h>
#include "P1.h"
void dl_push_element_end(struct doubly_node *head ,struct doubly_node *tail ,int new_element_value){///adds a new element to the circular list
    struct doubly_node *new_element = malloc(sizeof(struct doubly_node));
    struct doubly_node *last_element = malloc(sizeof(struct doubly_node));
    new_element -> info = new_element_value;///give the value of the new element
    last_element = tail -> previous;///find the last element in the circular list
    last_element -> next = new_element;
    new_element -> next = tail;///make the new element be the last one
    new_element -> previous = last_element;///and the last one will be the first before it
    tail -> previous = new_element;
}
int random(int min_value, int max_value){///generates a number in a given range
    unsigned int counter = max_value - min_value, number = 0;
    while (counter != 0) {///this will repeat until the number has a chance to get the max value of range
        number += number * RAND_MAX + rand();
        counter /= RAND_MAX;
    }
    return number % (max_value - min_value + 1) + min_value;///in case the number exceeds the range of values
}
void generator(int tests)///generates the input data for a given test
{
    int test_iterator, number,iterator;
    char temp_name_in[20];
    for (test_iterator = 1; test_iterator <= tests; test_iterator ++)
    {
        sprintf(temp_name_in, "data\\test_%d.in", test_iterator);
        FILE* test_in = fopen (temp_name_in, "w");
        number=random(1000,1000000);
        fprintf(test_in,"%d %d\n",number, rand());///puts in the input file the number of children and the number of steps that must be counted in order to remove a child
        for(iterator = 0 ;iterator < number; iterator++)
        {
            fprintf(test_in,"%d ",rand());///generates and writes in an input file a number for a child in a given range
        }
        fclose(test_in);
    }
}
void ala_bala_portocala(struct doubly_node *head, struct doubly_node *tail, int k, FILE* test_out)
{
    struct doubly_node *element, *popped_element;
    element = head -> next;///initialization of the child with the first element of the circular list
    int iterator;
    while(head -> info != 0)///the game will repeat while there is at least a child that can be removed
    {
        for(iterator = 1; iterator < k; iterator ++)
            element = element -> next;///counts up to the child that will be removed
        popped_element = element;///takes the position of the child that must be removed
        fprintf(test_out,"%d ",element->info);///prints the number of the removed child
        element -> previous -> next = element -> next;///the previous child is put next to the next child from the removed child
        element -> next -> previous = element -> previous;///the next child is put next to the previous child from the removed child
        element = element -> next;///the next child takes the position on which the removed one stood
        free(popped_element);///free the memory allocated to the removed child
        head -> info--;///decrement the number of children from the circular list
    }
}

