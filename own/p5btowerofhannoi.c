#include <stdio.h>
int count = 0;
void hanoi(int n, int src, int temp, int des) {
  if (n) {
    hanoi(n - 1, src, des, temp);
    printf("\nMove %d disk from %c to %c", n, src, des);
    count++;
    hanoi(n - 1, temp, src, des);
  }
}
int main() {
  int n;
  printf("Enter the Number of Disks: ");
  scanf("%d", &n);
  hanoi(n, 'A', 'B', 'C');
  printf("\nTotal moves: %d", count);
  return 0;
}