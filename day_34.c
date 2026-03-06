/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* top = NULL;
void push(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
int pop() {
    if (top == NULL) {
        return 0; // Return 0 for empty stack
    }
    Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}
int evaluatePostfix(char* expression) {
    for (int i = 0; expression[i] != '\0'; i++) {
        char token = expression[i];
        if (token >= '0' && token <= '9') {
            push(token - '0'); // Convert char to int
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            int operand2 = pop();
            int operand1 = pop();
            int result;
            switch (token) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
            }
            push(result);
        }
    }
    return pop(); // Final result
}
int main() {
    char expression[100];
    printf("Enter a postfix expression: ");
    fgets(expression, sizeof(expression), stdin);
    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);
    return 0;
}
