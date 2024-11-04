#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "a3q1_header.h"

// The createNode function allocates memory to the tree and creates a new node using the given data before returning the node.
Node* createNode(char *data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// The parseExpression function parses the expression string passed in from command line, stores the information in a new node, and returns the root node of the tree.
Node* parseExpression(char *expr){
    int len = strlen(expr);

    // Remove outer parentheses if they enclose the entire expression
    if (expr[0] == '(' && expr[len - 1] == ')') {
        expr[len - 1] = '\0'; // Remove the last parenthesis
        expr++;               // Move the pointer to skip the first parenthesis
        len -= 2;             // Adjust length
    }

    // Base case: if it's a single operand, create a leaf node
    if (isdigit(expr[0]) || isalpha(expr[0])) {
        return createNode(expr);
    }

    // Find the main operator (/, *, +, -) at the top level
    int balance = 0;
    int mainOpIndex = -1;
    for (int i = 0; i < len; i++) {
        if (expr[i] == '(') balance++;
        else if (expr[i] == ')') balance--;
        else if ((expr[i] == '/' || expr[i] == '*' || expr[i] == '+' || expr[i] == '-') && balance == 0) {
            mainOpIndex = i;
            break;
        }
    }

    // If no operator is found, return NULL (malformed expression)
    if (mainOpIndex == -1) {
        return NULL;
    }

    // Create a node for the main operator
    char op[2] = {expr[mainOpIndex], '\0'};
    Node* root = createNode(op);

    // Split the expression into left and right sub-expressions
    char leftExpr[mainOpIndex + 1];
    strncpy(leftExpr, expr, mainOpIndex);
    leftExpr[mainOpIndex] = '\0';

    char *rightExpr = expr + mainOpIndex + 1;

    // Recursively parse the left and right sub-expressions
    root->left = parseExpression(leftExpr);
    root->right = parseExpression(rightExpr);

    return root;
}

// The preOrder function prints tree nodes in preorder traversal.
void preorder(Node *root) {
    
}


// The inOrder function prints tree nodes in inorder traversal fully parenthesized.
void inorder(Node *root){

}

// The postOrder function prints tree nodes in postorder traversal.
void postorder(Node *root){

}

// The promptVariables function prompts the user to assign values to each variable found in the expression tree. The values should be stored in the Variables struct.
void promptVariables(Node *root){

}

// The calculate function calculates the expression and returns its result. Division by 0 and/or other error scenarios should be checked.
float calculate(Node *root){

}