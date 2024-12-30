#include<stdio.h>
#include<stdlib.h>
int f, r, a[10][10], q[20], v, u, n, s[10] = {0};
void bfs() {
    r = -1; f = 0; s[u] = 1; q[++r] = u;
    printf("Nodes visited from %d:\n%d\t", u, u);
    while(f <= r) {
        u = q[f++];
        for(v = 1; v <= n; v++) {
            if(a[u][v] == 1 && !s[v]) {
                printf("%d\t", v);
                q[++r] = v;
                s[v] = 1;
            }
        }
    }
    printf("\n");
}
int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the starting node: ");
    scanf("%d", &u);
    if (u < 1 || u > n) {
        printf("Invalid starting node!\n");
        return 1;
    }
    bfs();
    return 0;
}