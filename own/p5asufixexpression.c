#include <stdio.h>
#include <math.h>
#include <ctype.h>
double compute(char op, double a, double b) {
    return (op == '+') ? a + b : (op == '-') ? a - b : (op == '*') ? a * b : (op == '/') ? a / b : (op == '^' || op == '$') ? pow(a, b) : (op == '%') ? fmod(a, b) : 0;
}
int main() {
    double s[100], res;
    int top = -1;
    char postfix[100], symbol;
    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    for (int i = 0; postfix[i]; i++) {
        symbol = postfix[i];
        if (isspace(symbol)) continue;
        if (isdigit(symbol)) s[++top] = symbol - '0';
        else {
            double op2 = s[top--], op1 = s[top--];
            s[++top] = compute(symbol, op1, op2);
        }
    }
    printf("Result: %f\n", s[top]);
    return 0;
}