#include <stdio.h>
#include <stdlib.h>
#define max 4
int q[max], front = 0, rear = -1, count = 0;
void insert(int item) {
  if (count == max) printf("\nQueue Full!");
  else {
    rear = (rear + 1) % max;
    q[rear] = item;
    count++;
  }
}
void del() {
  if (count == 0) printf("\nQueue Empty!");
  else {
    printf("\nItem Deleted: %d", q[front]);
    front = (front + 1) % max;
    count--;
  }
}
void display() {
  if (count == 0) printf("\nQueue Empty!");
  else {
    printf("\nQueue: ");
    for (int i = 0; i < count; i++) {
      printf("%d ", q[(front + i) % max]);
    }
  }
}
int main() {
  int ch, item;
  while (1) {
    printf("\n1.Insert 2.Delete 3.Display 4.Exit\nChoice: ");
    scanf("%d", &ch);
    switch (ch) {
      case 1: printf("Enter item: "); scanf("%d", &item); insert(item); break;
      case 2: del(); break;
      case 3: display(); break;
      case 4: exit(0); break;
      default: printf("Invalid Choice!"); break;
    }
  }
  return 0;
}