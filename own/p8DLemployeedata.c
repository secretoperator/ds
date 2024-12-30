#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct node {
    int ssn;
    char name[15], dept[10], desig[20], phno[15];
    int salary;
    struct node *prev, *next;
};

typedef struct node NODE;

int countnodes(NODE *head) {
    NODE *temp = head;
    int count = 0;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

NODE *getnode() {
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    if (!newnode) {
        printf("\nMemory allocation failed!!\n");
        return NULL;
    }
    newnode->prev = newnode->next = NULL;
    printf("Enter SSN: "); scanf("%d", &newnode->ssn);
    printf("Enter Name: "); scanf("%14s", newnode->name);
    printf("Enter Department: "); scanf("%9s", newnode->dept);
    printf("Enter Designation: "); scanf("%19s", newnode->desig);
    printf("Enter Salary: "); scanf("%d", &newnode->salary);
    printf("Enter PhoneNo.: "); scanf("%14s", newnode->phno);
    return newnode;
}

NODE *display(NODE *head) {
    if (!head) {
        printf("Database Empty!!\n");
        return head;
    }
    printf("SSN\tNAME\t\tDEPARTMENT\tDESIGNATION\tSALARY\tPHONENO\n");
    NODE *temp = head;
    while (temp) {
        printf("%d\t%s\t\t%s\t\t%s\t%d\t%s\n", temp->ssn, temp->name, temp->dept, temp->desig, temp->salary, temp->phno);
        temp = temp->next;
    }
    printf("Total number of nodes: %d\n", countnodes(head));
    return head;
}

NODE *insertrear(NODE *head) {
    if (countnodes(head) == MAX) {
        printf("Database Full!!\n");
        return head;
    }
    NODE *newnode = getnode();
    if (!head) return newnode;
    NODE *temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}

NODE *insertfront(NODE *head) {
    if (countnodes(head) == MAX) {
        printf("Database Full!!\n");
        return head;
    }
    NODE *newnode = getnode();
    if (!head) return newnode;
    newnode->next = head;
    head->prev = newnode;
    return newnode;
}

NODE *insert(NODE *head) {
    int ch;
    while (1) {
        printf("1. Insert Front\t2. Insert Rear\t3. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        if (ch == 3) break;
        if (ch == 1) head = insertfront(head);
        else if (ch == 2) head = insertrear(head);
        head = display(head);
    }
    return head;
}

NODE *del_rear(NODE *head) {
    if (!head) return head;
    NODE *temp = head;
    if (!temp->next) {
        free(temp);
        printf("Data Deleted!\n");
        return NULL;
    }
    while (temp->next) temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    printf("Data Deleted!\n");
    return head;
}

NODE *del_front(NODE *head) {
    if (!head) return head;
    NODE *temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    free(temp);
    printf("Data Deleted!\n");
    return head;
}

NODE *del(NODE *head) {
    int ch;
    while (1) {
        printf("1. Delete Front\t2. Delete Rear\t3. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        if (ch == 3) break;
        if (ch == 1) head = del_front(head);
        else if (ch == 2) head = del_rear(head);
        head = display(head);
    }
    return head;
}

NODE *dqueue(NODE *head) {
    int ch;
    while (1) {
        printf("\nDLL used as Double Ended Queue\n1. Insert at Rear\n2. Delete from Front\n3. Insert at Front\n4. Delete from Rear\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        if (ch == 6) break;
        if (ch == 1) head = insertrear(head);
        else if (ch == 2) head = del_front(head);
        else if (ch == 3) head = insertfront(head);
        else if (ch == 4) head = del_rear(head);
        head = display(head);
    }
    return head;
}

NODE *create(NODE *head) {
    int n;
    printf("How many records you want to create? : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\nEnter Employee%d Details:--\n", i + 1);
        head = insertfront(head);
    }
    return head;
}

int main() {
    NODE *head = NULL;
    int ch;
    while (1) {
        printf("-------EMPLOYEE DATABASE SYSTEM ------\n1. Create\t2. Display\t3. Insert\t4. Delete\t5. Queue\t6. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        if (ch == 6) break;
        if (ch == 1) head = create(head);
        else if (ch == 2) head = display(head);
        else if (ch == 3) head = insert(head);
        else if (ch == 4) head = del(head);
        else if (ch == 5) head = dqueue(head);
        else printf("Invalid choice!!\n");
    }
    return 0;
}