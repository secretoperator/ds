#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASH_SIZE 100
typedef struct { char name[30]; int id; } EMPLOYEE;
int H(int k) { return k % HASH_SIZE; }
void insert(EMPLOYEE a[], int id, char name[]) {
    for (int i = 0; i < HASH_SIZE; i++) {
        int idx = (H(id) + i) % HASH_SIZE;
        if (!a[idx].id) { a[idx].id = id; strcpy(a[idx].name, name); return; }
    }
    printf("\nTABLE FULL!\n");
}
void display(EMPLOYEE a[]) {
    printf("\nHASHNO.\tINDEX\tNAME\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        if (a[i].id) printf("%d\t%d\t%s\n", a[i].id, i, a[i].name);  // Print ID, index, and name
    }
}
int main() {
    EMPLOYEE a[HASH_SIZE] = {0};
    int ch, id;
    char name[30];
    while (1) {
        printf("HASH_TABLE\n1.INSERT\n2.DISPLAY\n3.EXIT\nEnter Your Choice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("\nEnter name: ");
            scanf("%29s", name);  // Ensure no buffer overflow
            printf("Enter id: ");
            scanf("%d", &id);
            insert(a, id, name);
        } else if (ch == 2) {
            display(a);  // Display the hash table
        } else if (ch == 3) {
            exit(0);
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}