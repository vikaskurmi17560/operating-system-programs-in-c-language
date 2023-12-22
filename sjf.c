#include <stdio.h>
#include <stdlib.h>
struct Process
{
    char prc[10];
    int At;
    int Bt;
    int Ct;
    int Tat;
    int wt;
};
void swap(struct Process *a, struct Process *b)
{
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}
void sjfScheduling(struct Process arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].Bt > arr[j + 1].Bt)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    int currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        if (currentTime < arr[i].At)
        {
            currentTime = arr[i].At;
        }
        arr[i].Ct = currentTime + arr[i].Bt;
        arr[i].Tat = arr[i].Ct - arr[i].At;
        arr[i].wt = arr[i].Tat - arr[i].Bt;
        currentTime = arr[i].Ct;
    }
}
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter details for Process %d:\n", i + 1);
        printf("Process ID: ");
        scanf("%s", arr[i].prc);
        printf("Arrival Time: ");
        scanf("%d", &arr[i].At);
        printf("Burst Time: ");
        scanf("%d", &arr[i].Bt);
    }
    sjfScheduling(arr, n);
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", arr[i].prc, arr[i].At, arr[i].Bt, arr[i].Ct, arr[i].Tat, arr[i].wt);
    }
    return 0;
}
