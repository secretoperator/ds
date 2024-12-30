#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *llink, *rlink;
} NODE;
NODE* insert(NODE *root, int item) {
    NODE *temp = malloc(sizeof(NODE));
    if (!temp) return root;
    temp->data = item; temp->llink = temp->rlink = NULL;
    if (!root) return temp;
    NODE *cur = root, *prev = NULL;
    while (cur) { prev = cur; cur = (item < cur->data) ? cur->llink : cur->rlink; }
    if (item < prev->data) prev->llink = temp; else prev->rlink = temp;
    return root;
}
NODE* construct_bsf(NODE *root) {
    int n, a;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter Elements: ");
    while (n--) { scanf("%d", &a); root = insert(root, a); }
    printf("Tree created Successfully!\n");
    return root;
}
void search_item(NODE *root, int key) {
    while (root) {
        if (root->data == key) { printf("Key found!\n"); return; }
        root = (key < root->data) ? root->llink : root->rlink;
    }
    printf("Key not found!\n");
}
void preorder(NODE *root) { if (root) { printf("%d\t", root->data); preorder(root->llink); preorder(root->rlink); } }
void postorder(NODE *root) { if (root) { postorder(root->llink); postorder(root->rlink); printf("%d\t", root->data); } }
void inorder(NODE *root) { if (root) { inorder(root->llink); printf("%d\t", root->data); inorder(root->rlink); } }
int main() {
    NODE *root = NULL;
    int ch, key;
    while (1) {
        printf("\n1. Construct Tree\n2. Preorder\n3. Postorder\n4. Inorder\n5. Search\n6. Exit\nEnter your Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: root = construct_bsf(root); break;
            case 2: preorder(root); break;
            case 3: postorder(root); break;
            case 4: inorder(root); break;
            case 5: printf("Enter key to search: "); scanf("%d", &key); search_item(root, key); break;
            case 6: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
    return 0;
}