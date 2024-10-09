/*
Name: Faiz Mustansar
Student ID: 1261489
Assignment 2, Question 2
*/

#include "q2.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Pushes a new value onto the stack.
 *
 * @param stack Pointer to the pointer of the stack's head.
 * @param value The value to be added to the stack.
 */
void push(Operand **stack, double value)
{
    Operand *new_node = (Operand *)malloc(sizeof(Operand));

    if (new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    new_node->value = value;

    // link the new node to the head of the stack
    new_node->next = *stack;

    // update head of the stack towards the new node
    *stack = new_node;
}

/**
 * Pops the top value from the stack and returns it.
 *
 * @param stack Pointer to the pointer of the stack's head.
 * @return The value that was at the top of the stack.
 */
double pop(Operand **stack)
{
    if (*stack == NULL)
    {
        printf("Stack is Empty");
        return -1;
    }
    double temp = (*stack)->value;

    *stack = (*stack)->next;
    return temp;
}

/**
 * Prints all values in the stack.
 *
 * @param stack Pointer to the stack's head.
 */
void print(Operand *stack)
{
    if (stack == NULL)
    {
        printf("Nothing in Stack");
        return;
    }
    while (stack != NULL)
    {
        printf("Stack Value: %.2f\n", stack->value);
        stack = stack->next;
    }
}