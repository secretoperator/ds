#include <stdio.h>
int n, a[10][10], visited[10] = {0};
void dfs(int u) {
    printf("%d ", u);
    visited[u] = 1;
    for (int v = 1; v <= n; v++)
        if (!visited[v] && a[u][v])
            dfs(v);
}
int main() {
    printf("Enter nodes: ");
    scanf("%d", &n);
    printf("Enter matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    int u;
    printf("Enter start: ");
    scanf("%d", &u);
    printf("Nodes: ");
    dfs(u);
    return 0;
}