#include<stdio.h>
#include<stdlib.h>
#define max 5
struct node {
    char usn[11], name[15], branch[5], phone[15];
    int sem;
    struct node *next;
};
typedef struct node NODE;
int countnodes(NODE *head) {
    NODE *p = head;
    int count = 0;
    while (p) { p = p->next; count++; }
    return count;
}
NODE* getnode() {
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    if (!newnode) { printf("Memory allocation failed!"); return NULL; }
    printf("Enter USN:"); scanf("%s", newnode->usn);
    printf("Enter Name:"); scanf("%s", newnode->name);
    printf("Enter Branch:"); scanf("%s", newnode->branch);
    printf("Enter Sem:"); scanf("%d", &newnode->sem);
    printf("Enter Phone No:"); scanf("%s", newnode->phone);
    newnode->next = NULL;
    return newnode;
}
NODE* display(NODE* head) {
    if (!head) { printf("No Student Details to Display!!\n"); return NULL; }
    NODE *p = head;
    printf("\nUSN\tNAME\tBRANCH\tSEM\tPHONE NO.\n");
    while (p) { printf("%s\t\t%s\t\t%s\t\t%d\t\t%s\n", p->usn, p->name, p->branch, p->sem, p->phone); p = p->next; }
    printf("Total Students: %d\n", countnodes(head));
    return head;
}
NODE* insert_front(NODE *head) {
    if (countnodes(head) == max) { printf("Database Full!!\n"); return head; }
    NODE *newnode = getnode();
    newnode->next = head;
    return newnode;
}
NODE* insert_rear(NODE *head) {
    if (countnodes(head) == max) { printf("Database Full!!\n"); return head; }
    NODE *newnode = getnode();
    if (!head) return newnode;
    NODE *temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newnode;
    return head;
}
NODE* del_front(NODE *head) {
    if (!head) { printf("Database Empty!!\n"); return head; }
    NODE *temp = head;
    head = head->next;
    free(temp);
    printf("Data Deleted!!\n");
    return head;
}
NODE* del_rear(NODE *head) {
    if (!head) { printf("Database Empty!!\n"); return head; }
    if (!head->next) { free(head); printf("Data Deleted!!\n"); return NULL; }
    NODE *temp = head;
    while (temp->next && temp->next->next) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    printf("Data Deleted!!\n");
    return head;
}
NODE* insert(NODE *head) {
    int ch;
    while (1) {
        printf("1.insert_front 2.insert_rear 3.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        if (ch == 1) head = insert_front(head);
        else if (ch == 2) head = insert_rear(head);
        else break;
        display(head);
    }
    return head;
}
NODE* del(NODE *head) {
    int ch;
    while (1) {
        printf("1.del_front 2.del_rear 3.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        if (ch == 1) head = del_front(head);
        else if (ch == 2) head = del_rear(head);
        else break;
        display(head);
    }
    return head;
}
NODE* stack(NODE *head) {
    int ch;
    while (1) {
        printf("SSL used as Stack...\n1.Insert at Front(PUSH) 2.Delete from Front(POP) 3.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        if (ch == 1) head = insert_front(head);
        else if (ch == 2) head = del_front(head);
        else break;
        display(head);
    }
    return head;
}
NODE* create(NODE *head) {
    if (!head) head = getnode();
    else head = insert_front(head);
    return head;
}
int main() {
    int ch, i, n;
    NODE *head = NULL;
    printf("*----------StudentDatabase-----------*\n");
    do {
        printf("1.Create 2.Display 3.Insert 4.Delete 5.Stack 6.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("How many student data you want to create: "); scanf("%d", &n);
                    for (i = 0; i < n; i++) { printf("Enter Student%d Details:--\n", i + 1); head = create(head); }
                    break;
            case 2: display(head); break;
            case 3: head = insert(head); break;
            case 4: head = del(head); break;
            case 5: head = stack(head); break;
            case 6: break;
        }
    } while (ch != 6);
    return 0;
}