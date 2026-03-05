/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/

#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct Stack {
    char arr[MAX];
    int top;
} Stack;
void initStack(Stack* s) {
    s->top = -1;
}
int isFull(Stack* s) {
    return s->top == MAX - 1;
}
int isEmpty(Stack* s) {
    return s->top == -1;
}
void push(Stack* s, char value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = value;
}
char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->arr[s->top--];
}
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];
        if ((token >= 'A' && token <= 'Z') || (token >= 'a' && token <= 'z')) {
            postfix[j++] = token; 
        } else if (token == '(') {
            push(&s, token); 
        } else if (token == ')') {
            while (!isEmpty(&s) && s.arr[s.top] != '(') {
                postfix[j++] = pop(&s); 
            }
            pop(&s); 
        } else {
            while (!isEmpty(&s) && precedence(s.arr[s.top]) >= precedence(token)) {
                postfix[j++] = pop(&s); 
            }
            push(&s, token); 
        }
    }
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s); 
    }
    postfix[j] = '\0'; 
}
int main() {
    char infix[MAX], postfix[MAX];
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);
    return 0;
}
