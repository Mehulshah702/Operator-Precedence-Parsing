#include <stdio.h>
#include <ctype.h>

int stack[50];
int top = -1;

// Function to push an element onto the stack
void push(int item) {
    stack[++top] = item;
}

// Function to pop an element from the stack
int pop() {
    return stack[top--];
}

// Function to check if the character is an operator
int isOperator(char symbol) {
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
        return 1;
    return 0;
}

// Function to get the precedence of an operator
int getPrecedence(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Function to perform Operator Precedence Parsing
void parseExpression(char expression[]) {
    int i, token;
    char symbol;

    for (i = 0; expression[i] != '\0'; i++) {
        symbol = expression[i];

        if (isalnum(symbol)) {
            printf("%c ", symbol);
        } else if (isOperator(symbol)) {
            while (top != -1 && getPrecedence(stack[top]) >= getPrecedence(symbol)) {
                printf("%c ", pop());
            }
            push(symbol);
        } else if (symbol == '(') {
            push(symbol);
        } else if (symbol == ')') {
            while (stack[top] != '(') {
                printf("%c ", pop());
            }
            pop(); // Pop '(' from the stack
        }
    }

    while (top != -1) {
        printf("%c ", pop());
    }
}

int main() {
    char expression[50];

    printf("Enter an infix expression: ");
    scanf("%s", expression);

    printf("Postfix expression: ");
    parseExpression(expression);

    return 0;
}