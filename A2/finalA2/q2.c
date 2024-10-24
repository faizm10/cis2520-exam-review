/*
Name: Faiz Mustansar
Student ID: 1261489
Assignment: A2
Date: Oct 11, 2024
*/

#include "q2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
  if (argc != 2) {
    printf("Usage: %s <postfix_expression>\n", argv[0]);
    return 1;
  }

  Operand *stack = NULL; // Pointer to the stack

  // Loop through the second command-line argument, containing the operands and the operators
  for (int i = 0; i < strlen(argv[1]); ++i)
  {
    char current = argv[1][i];

    // If the character is a digit, push it to the stack (convert char to double)
    if (isdigit(current))
    {
      double value = current - '0'; // Convert character to double
      push(&stack, value);
    }
    else if (current == '*' || current == '+' || current == '-' || current == '/')
    {
      if (stack == NULL || stack->next == NULL) {
        printf("Error: Not enough operands for operation '%c'\n", current);
        return 1; // Exit on error
      }

      // Pop two operands from the stack
      double secondOperand = pop(&stack);
      double firstOperand = pop(&stack);
      double result;

      // Perform the operation based on the operator
      switch (current) {
        case '*':
          result = firstOperand * secondOperand;
          break;
        case '+':
          result = firstOperand + secondOperand;
          break;
        case '-':
          result = firstOperand - secondOperand;
          break;
        case '/':
          if (secondOperand == 0) {
            printf("Error: Division by zero\n");
            return 1; // Exit on error
          }
          result = firstOperand / secondOperand;
          break;
        default:
          printf("Error: Unsupported operator '%c'\n", current);
          return 1; // Exit on error
      }

      // Push the result back onto the stack
      push(&stack, result);
    }
    else
    {
      // If it's not a digit or operator, print a warning and ignore it
      printf("Warning: Ignored non-digit, non-operator character '%c'\n", current);
    }
  }

  // After processing the input, the final result should be on top of the stack
  if (stack != NULL && stack->next == NULL) {
    printf("Final result: %.2f\n", pop(&stack)); // Print the final result
  } else {
    printf("Error: The expression is invalid\n");
    return 1; // Exit on error
  }

  return 0;
}
