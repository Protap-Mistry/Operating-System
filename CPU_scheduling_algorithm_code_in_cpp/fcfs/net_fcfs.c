#include<stdio.h>

 int main()

{
    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    printf("Enter total number of processes(maximum 20):");
    scanf("%d",&n);

    printf("\nEnter Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }

    wt[0]=0;

    for(i=1;i<n;i++)
    {
        wt[i]=0; //First, the waiting time of the first process is zero.
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
            /*Calculation of the waiting time is done by adding the burst time of the previous process.
             Consider the previous process had a burst time of 10, then the waiting time of second
              will be 10. Similarly, for the third process, the waiting time will
              the sum of burst times of first and second processes. */
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        /* The next part we calculate the turn around time. The turn around time for each process
        is calculated by adding the burst time and the waiting time.*/
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }

    avwt/=i;
    avtat/=i;

    /*i gives the total number of processes.
    We divide the sum of all the waiting times and turn around times to get the average. */

    printf("\n\nAverage Waiting Time:%d",avwt);
    printf("\nAverage Turnaround Time:%d",avtat);

    return 0;
}
