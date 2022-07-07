#include <stdio.h>
#include <stdlib.h>
int random(int min_value, int max_value){///generates a number in a given range
    unsigned int counter = max_value - min_value, number = 0;
    while (counter != 0) {///this will repeat until the number has a chance to get the max value of range
        number += number * RAND_MAX + rand();
        counter /= RAND_MAX;
    }
    return number % (max_value - min_value + 1) + min_value;///in case the number exceeds the range of values
}
void no_pages(int no_digits, FILE* test_out)
{
    int sum = 0 , iterator = 1 , pages = 0, counter = 9;///initialization of sum for sum of digits currently used to create pages
    ///iterator for number of digits of the current pages, pages for number of pages generated and counter for number of pages with iterator digits
    while(sum + counter * iterator < no_digits)///comparison in order to find out if we can generate all the numbers with iterator  digits
    {
        sum += counter * iterator;///adding the digits used to generate all the pages with iterator digits to the sum
        pages += counter;///add the pages generated with iterator digits to the sum
        iterator++;///increment iterator
        counter *= 10;///multiply the number of pages with i digits by 10
    }
    pages += (no_digits - sum) / iterator;///add the remaining pages that have iterator digits that can be created
    fprintf(test_out,"With %d digits can be generated %d pages, remaining %d digits unused", no_digits, pages,(no_digits - sum) % iterator);
}
