#include <stdio.h>
struct process
{
    char prc[10];
    int At;
    int Bt;
    int Ct;
    int Tat;
    int wt;
    int Pt;
};
int main()
{
    struct process arr[10];
    float It = 0;
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("Enter the process id :\n");
        scanf("%s", arr[i].prc);
        arr[i].At = 0;
        printf("\nEnter the Burst time :");
        scanf("%d", &arr[i].Bt);
        printf("\nEnter the priority :");
        scanf("%d", &arr[i].Pt);
    }
    for (i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (arr[i].Pt > arr[j].Pt)
            {
                int temp = arr[i].Pt;
                arr[i].Pt = arr[j].Pt;
                arr[j].Pt = temp;
            }
        }
    }
    arr[0].Ct = arr[0].Bt - arr[0].At;
    for (i = 1; i < 5; i++)
    {
        if (arr[i].At >> arr[i - 1].Ct)
        {
            It = It + (arr[i].At - arr[i - 1].Ct);
            arr[i].Ct = arr[i].At + arr[i].Bt;
        }
        else
        {
            arr[i].Ct = arr[i - 1].Ct + arr[i].Bt;
        }
    }
    float last = arr[4].Ct;
    for (i = 0; i < 4; i++)
    {
        arr[i].Tat = arr[i].Ct - arr[i].At;
        arr[i].wt = arr[i].Tat - arr[i].Bt;
    }
    double sum = 0;
    for (i = 0; i < 4; i++)
    {
        sum = sum + arr[i].Tat;
    }
    float avgtat = sum / 4;
    sum = 0;
    for (i = 0; i < 4; i++)
    {
        sum = sum + arr[i].wt;
    }
    float avgwt = sum / 5;
    float throughput = 5 / last;
    float Cpuuti = ((last - It) / last) * 100;
    float idleness = (It / last) * 100;
    for (i = 0; i < 4; i++)
    {
        printf("\n%s\t", arr[i].prc);
        printf("%d\t", arr[i].At);
        printf("%d\t", arr[i].Bt);
        printf("%d\t", arr[i].Ct);
        printf("%d\t", arr[i].Tat);
        printf("%d\t", arr[i].wt);
        printf("%d\t", arr[i].Pt);
    }
    printf("\n%f", avgtat);
    printf("\n%f", avgwt);

    printf("\n%f", throughput);
    printf("\n%f", Cpuuti);
    printf("\n%f\n", idleness);
    return 0;
}
