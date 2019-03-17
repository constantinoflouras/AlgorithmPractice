/*
    File:       knapsack.c
    Author:     Constantino Flouras
    Description:
        Implementation of the knapsack problem, as described in
        Chapter 42 of Algorithms, 2nd Edition by Robert Sedgewick
*/

#include <string.h>

/*
    Typedef:    knapsack_item
    Description:
        Structure that stores a possible knapsack item.
        Generally speaking, these possible items would be stored in an array.
*/
typedef struct knapsack_item
{
    int n_size;
    int n_value;
    char * a_name;
} t_knapsack_item;

/*
    Function:   main
    Description:
        Main execution path for the program.
*/
int main(int argc, char * argv[])
{
    /*  Declare and initialize an array of possible knapsack items  */
    t_knapsack_item a_items[5] =
    {
        {3, 4, "Item A"},
        {4, 5, "Item B"},
        {7, 10, "Item C"},
        {8, 11, "Item D"},
        {9, 13, "Item E"},
    };
    int NUM_ITEMS = (sizeof(a_items) / sizeof(a_items[0]));
    
    /*  Declare and initialize arrays to store possible combinations    */
    int MAX_CAPACITY = 10;
    int a_value[MAX_CAPACITY];  /*  Stores maximum value at each capacity   */
    memset(a_value, 0, sizeof(int) * MAX_CAPACITY);
    int a_best[MAX_CAPACITY];
    memset(a_value, 0, sizeof(int) * MAX_CAPACITY);
    
    
    /*  */
    
    /*  For each potential knapsack item; we should run through the calculation.    */
    int n_item_iter = 0;
    for (n_item_iter = 0; n_item_iter < NUM_ITEMS; n_item_iter++)
    {
        printf("ITEM #%d: ", n_item_iter);
        /*  For each potential knapsack capacity, calculate the maximum size possible
            given this item, and all preceding items.   */
        int n_capacity_iter = 0;
        for (n_capacity_iter = 0; n_capacity_iter < MAX_CAPACITY; n_capacity_iter++)
        {
            /*  Test and see if we could fit another a_items[n_item_iter] within
                this specific capacity  */
            if (    (n_capacity_iter - a_items[n_item_iter].n_size >= 0)
                &&  (a_value[n_capacity_iter] < a_value[n_capacity_iter - a_items[n_item_iter].n_size] + a_items[n_item_iter].n_value)  )
            {
                a_value[n_capacity_iter] = a_value[n_capacity_iter - a_items[n_item_iter].n_size] + a_items[n_item_iter].n_value;
                a_best[n_capacity_iter] = n_item_iter;
            }
            
            /*  Print statements    */
            printf(" %2d %s", a_value[n_capacity_iter], n_capacity_iter == MAX_CAPACITY - 1 ? "\n" : "");
        }
    }
}

/*
    Psuedocode:
    
    for each possible knapsack_item
    {
        for each possible size from 0 to MAX
        {
            if
        }
    }
*/