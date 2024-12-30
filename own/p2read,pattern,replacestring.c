#include <stdio.h>
#include <string.h>
char str[50], pat[50], rep[50], ans[50];
void stringmatch() {
    int i = 0, j = 0, c = 0, m = 0;
    while (str[c]) {
        if (str[m] == pat[i]) {
            if (++i == strlen(pat)) {
                for (int k = 0; rep[k]; k++) ans[j++] = rep[k];
                m = ++c; i = 0;
            } else {
                m++; c++;
            }
        } else {
            ans[j++] = str[c++];
            m = c; i = 0;
        }
    }
    ans[j] = '\0';
}
int main() {
    printf("\nEnter a Main String:\n"); fgets(str, sizeof(str), stdin);
    printf("\nEnter a Pattern String:\n"); fgets(pat, sizeof(pat), stdin);
    printf("\nEnter a Replacement String:\n"); fgets(rep, sizeof(rep), stdin);
    str[strcspn(str, "\n")] = 0;
    pat[strcspn(pat, "\n")] = 0;
    rep[strcspn(rep, "\n")] = 0;
    stringmatch();
    if (strchr(ans, '\0')) printf("\nThe resultant string is:\n%s", ans);
    else printf("\nPattern String not found!!\n");
    return 0;
}