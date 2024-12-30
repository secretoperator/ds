#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char *dayname, *activity;
    int date;
} DAY;
void create(DAY *d) {
    d->dayname = malloc(20); d->activity = malloc(50);
    printf("Enter Dayname, Date, Activity: ");
    scanf("%s %d %s", d->dayname, &d->date, d->activity);
}
int main() {
    int n;
    printf("Enter number of days: ");
    scanf("%d", &n);
    DAY *calendar = malloc(n * sizeof(DAY));
    if (!calendar) return printf("Memory Allocation Failed!\n"), 1;
    for (int i = 0; i < n; i++) {
        printf("Day %d: ", i + 1);
        create(&calendar[i]);
    }
    printf("\nActivity Details\n-------------------------------\nDay\tName\tDate\tActivity\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%s\t%d\t%s\n", i + 1, calendar[i].dayname, calendar[i].date, calendar[i].activity);
    for (int i = 0; i < n; i++) { free(calendar[i].dayname); free(calendar[i].activity); }
    free(calendar);
    return 0;
}