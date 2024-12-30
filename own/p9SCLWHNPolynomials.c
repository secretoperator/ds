#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node {
    int cf, px, py, pz;
    struct node *next;
};
typedef struct node NODE;
NODE* getnode() {
    NODE *x = (NODE*)malloc(sizeof(NODE));
    x->next = NULL; return x;
}
NODE* insert(NODE *head, int cf, int px, int py, int pz) {
    NODE *temp = getnode();
    temp->cf = cf; temp->px = px; temp->py = py; temp->pz = pz;
    NODE *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = temp; return head;
}
void display(NODE *head) {
    if (!head->next) { printf("Polynomial does not exist.\n"); return; }
    for (NODE *cur = head->next; cur; cur = cur->next) {
        printf("%dx^%dy^%dz^%d", cur->cf, cur->px, cur->py, cur->pz);
        if (cur->next) printf(" + ");
    }
    printf("\n");
}
NODE* read_poly() {
    NODE *head = getnode(); int cf, px, py, pz, ch;
    do {
        printf("Enter coeff and powers of x, y, z: ");
        scanf("%d %d %d %d", &cf, &px, &py, &pz);
        head = insert(head, cf, px, py, pz);
        printf("Continue? (1/0): ");
        scanf("%d", &ch);
    } while (ch);
    return head;
}
void evaluate(NODE *head) {
    int x, y, z; float result = 0.0;
    printf("Enter x, y, z values: ");
    scanf("%d%d%d", &x, &y, &z);
    for (NODE *cur = head->next; cur; cur = cur->next)
        result += cur->cf * pow(x, cur->px) * pow(y, cur->py) * pow(z, cur->pz);
    printf("Polynomial result: %.6f\n", result);
}
NODE* add_poly(NODE *h1, NODE *h2) {
    NODE *h3 = getnode(), *cur = h3;
    for (NODE *p1 = h1->next; p1; p1 = p1->next) {
        NODE *p2 = h2->next;
        while (p2) {
            if (p1->px == p2->px && p1->py == p2->py && p1->pz == p2->pz) {
                cur = insert(cur, p1->cf + p2->cf, p1->px, p1->py, p1->pz);
                p2 = NULL; break;
            }
            p2 = p2->next;
        }
        if (!p2) cur = insert(cur, p1->cf, p1->px, p1->py, p1->pz);
    }
    for (NODE *p2 = h2->next; p2; p2 = p2->next)
        cur = insert(cur, p2->cf, p2->px, p2->py, p2->pz);
    return h3;
}
int main() {
    NODE *h1, *h2, *h3; int ch;
    while (1) {
        printf("\n1. Evaluate polynomial\n2. Add polynomials\n3. Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: h1 = read_poly(); display(h1); evaluate(h1); break;
            case 2: printf("First polynomial:\n"); h1 = read_poly(); display(h1);
                    printf("Second polynomial:\n"); h2 = read_poly(); display(h2);
                    h3 = add_poly(h1, h2); printf("Sum of polynomials:\n"); display(h3); break;
            case 3: exit(0); break;
            default: printf("Invalid choice\n"); break;
        }
    }
    return 0;
}