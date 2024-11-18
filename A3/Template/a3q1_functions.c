#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "a3q1_header.h"

Variable variables[10];
int varCount = 0;
int isValidCharacter(char c) {
    return isdigit(c) || isalpha(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '.';
}
// FreeTree function to free memory allocated for the tree
void freeTree(Node *root)
{
    if (root == NULL)
        return;

    // Recursively free left and right subtrees
    freeTree(root->left);
    freeTree(root->right);

    // Free the current node
    free(root);
}

// The createNode function allocates memory to the tree and creates a new node using the given data before returning the node.
Node *createNode(char *data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	strcpy(newNode->data, data);
	newNode->left = newNode->right = NULL;
	return newNode;
}

// The parseExpression function parses the expression string passed in from command line, stores the information in a new node, and returns the root node of the tree.
Node *parseExpression(char *expr) {
    int len = strlen(expr);

    for (int i = 0; i < len; i++) {
        if (!isValidCharacter(expr[i])) {
            printf("Error: Unknown symbol '%c' in expression. Exiting.\n", expr[i]);
            exit(1);
        }
    }

    // If the expression is a single operand (no parentheses), create a node directly
    if (expr[0] != '(') {
        return createNode(expr);
    }

    // Strip the outermost parentheses
    expr[len - 1] = '\0';
    expr++;

    int balance = 0;
    for (int i = 0; i < len - 2; i++) {
        if (expr[i] == '(')
            balance++;
        else if (expr[i] == ')')
            balance--;

        // Find the main operator at balance zero (outside any inner expression)
        if (balance == 0 && (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')) {
            char op[2] = {expr[i], '\0'};
            Node *root = createNode(op);

            // Split expression at the operator, recursively parse left and right
            expr[i] = '\0';
            root->left = parseExpression(expr);
            root->right = parseExpression(expr + i + 1);
            return root;
        }
    }

    return NULL;
}

// The preOrder function prints tree nodes in preorder traversal.
void preorder(Node *root)
{
	if (root == NULL)
		return;

	// Print the current node's data without any extra parentheses or formatting
	printf("%s ", root->data);

	// Traverse the left and right children
	preorder(root->left);
	preorder(root->right);
}

// The inOrder function prints tree nodes in inorder traversal fully parenthesized.
void inorder(Node *root)
{
	if (root == NULL)
		return;

	// Check if the current node is a leaf node
	if (root->left == NULL && root->right == NULL)
	{
		printf("(%s)", root->data); // Print leaf nodes with parentheses
	}
	else
	{
		// Not a leaf node, print with normal parentheses structure
		if (root->left)
			printf("(");

		inorder(root->left);
		printf("%s", root->data);
		inorder(root->right);

		if (root->right)
			printf(")");
	}
}

// The postOrder function prints tree nodes in postorder traversal.
void postorder(Node *root)
{
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%s ", root->data);
}

// The promptVariables function prompts the user to assign values to each variable found in the expression tree. The values should be stored in the Variables struct.
void promptVariables(Node *root) {
    if (root == NULL) return;

    if (isalpha(root->data[0])) { // Check if it's a variable
        // Check if the variable has already been assigned a value
        for (int i = 0; i < varCount; i++) {
            if (strcmp(variables[i].varName, root->data) == 0) {
                return; // Variable already assigned, no need to prompt again
            }
        }

        // Prompt the user for the variable value
        float value;
        printf("Enter value for %s: ", root->data);
        scanf("%f", &value);

        // Store the variable and its value
        strcpy(variables[varCount].varName, root->data);
        variables[varCount].value = value;
        varCount++;
    }

    // Recursively prompt for variables in left and right subtrees
    promptVariables(root->left);
    promptVariables(root->right);
}

// The calculate function calculates the expression and returns its result. Division by 0 and/or other error scenarios should be checked.
float getVariableValue(char *varName)
{
	for (int i = 0; i < varCount; i++)
	{
		if (strcmp(variables[i].varName, varName) == 0)
		{
			return variables[i].value;
		}
	}
	return 0; // Default to 0 if variable not found
}

float calculate(Node *root)
{
	if (root == NULL)
		return 0;

	if (isdigit(root->data[0]) || (root->data[0] == '-' && isdigit(root->data[1])))
	{
		return atof(root->data);
	}
	else if (isalpha(root->data[0]))
	{
		return getVariableValue(root->data);
	}

	float left = calculate(root->left);
	float right = calculate(root->right);

	if (strcmp(root->data, "+") == 0)
		return left + right;
	else if (strcmp(root->data, "-") == 0)
		return left - right;
	else if (strcmp(root->data, "*") == 0)
		return left * right;
	else if (strcmp(root->data, "/") == 0)
	{
		if (right == 0)
		{
			printf("Error: Division by zero\n");
			return 0;
		}
		return left / right;
	}
	return 0;
}
