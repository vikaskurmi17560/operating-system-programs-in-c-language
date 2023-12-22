#include <stdio.h>
#include <stdio.h>
typedef struct processes
{
    char p[10];
    int bt;
    int at;
    int ct;
    int tat;
    int wt;

} processes;
int main()
{
    processes pr[4];
    float it = 0;
    for (int i = 0; i < 4; i++)
    {
        printf("enter process of %d", i + 1);
        scanf("%s", pr[i].p);
        printf("enter arrival of %d", i);
        scanf("%d", &pr[i].at);
        printf("enter burst time of %d", i);
        scanf("%d", &pr[i].bt);
    }
    pr[0].ct = pr[0].bt - pr[0].at;
    for (int i = 1; i < 4; i++)
    {
        if (pr[i].at > pr[i - 1].ct)
        {
            it += (pr[i].at - pr[i - 1].ct);
            pr[i].ct = pr[i].at + pr[i].bt;
        }
        else
        {
            pr[i].ct = pr[i - 1].ct + pr[i].bt;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        pr[i].tat = pr[i].ct - pr[i].at;
        pr[i].wt = pr[i].tat - pr[i].bt;
    }
    printf("process\tarrival\tburst\tct\twt\ttat\n");
    for (int i = 0; i < 4; i++)
    {
        printf("\n%s\t", pr[i].p);
        printf("%d\t", pr[i].at);
        printf("%d\t", pr[i].bt);
        printf("%d\t", pr[i].ct);
        printf("%d\t", pr[i].wt);
        printf("%d\t", pr[i].tat);
    }
    float sum = 0, sum2 = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += pr[i].tat;
        sum2 += pr[i].wt;
    }
    float tatAvg = sum / 4;
    float wtAvg = sum2 / 4;
    float throwput = 4 / pr[4].ct;
    float cpu = ((pr[4].ct - it) / pr[4].ct) * 100;
    float idelness = (it / pr[4].ct) * 100;

    printf("\n%f\t", tatAvg);
    printf("\n%f\t", wtAvg);
    printf("\n%f\t", throwput);
    printf("\n%f\t", cpu);
    printf("\n%f\t", idelness);
    return 0;
}
