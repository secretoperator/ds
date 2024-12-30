#include <stdio.h>
#define max 4
int stack[max], top = -1;
void push(int item) {
    if (top == max - 1) printf("\nStack is Full!");
    else stack[++top] = item;
}
void pop() {
    if (top == -1) printf("\nStack is Empty!");
    else printf("\nItem deleted = %d", stack[top--]);
}
void display() {
    if (top == -1) printf("\nStack is Empty!");
    else {
        printf("\nStack contents are :\n");
        for (int i = top; i >= 0; i--) printf("|%d|\n", stack[i]);
    }
}
void pallindrome() {
    int flag = 1;
    for (int i = 0; i <= top / 2; i++) {
        if (stack[i] != stack[top - i]) {
            flag = 0;
            break;
        }
    }
    printf("\nStack is %sPalindrome.", flag ? "" : "Not a ");
}
int main() {
    int ch, item;
    while (1) {
        printf("\n1.Push\t2.Pop\t3.Display\t4.Pallindrome\t5.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        if (ch == 5) break;
        switch (ch) {
            case 1: printf("\nEnter element: "); scanf("%d", &item); push(item); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: pallindrome(); break;
            default: printf("\nInvalid Choice!"); break;
        }
    }
    return 0;
}