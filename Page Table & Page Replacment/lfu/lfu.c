#include<stdio.h>
/*
1. Start least frequency used algorithm

2. Read Number Of Pages And Frames

3.Read Each Page Value

4. Search For Page In The Frames

5. If Not Available Allocate Free Frame

6. If No Frames Is Free Replace The Page With The Page That Is Least or smallest Used

7.Print Page Number Of Page Faults

8.Stop
*/

int main()
{
int f,p;
int pages[50],frame[10],hit=0,count[50],time[50];
int i,j,page,flag,least,minTime,temp;
printf("Enter no of frames : ");
scanf("%d",&f);

printf("Enter no of pages : ");
scanf("%d",&p);

for(i=0;i<f;i++)
{
    frame[i]=-1;
}
for(i=0;i<50;i++)
{
    count[i]=0;
}

printf("Enter page no : \n");
for(i=0;i<p;i++)
{
    scanf("%d",&pages[i]);
}

printf("\n");
for(i=0;i<p;i++)
{
    count[pages[i]]++;
    time[pages[i]]=i;
    flag=1;
    least=frame[0];

    for(j=0;j<f;j++)
    {
        if(frame[j]==-1 || frame[j]==pages[i])
        {
            if(frame[j]!=-1)
            {
                hit++;
            }
            flag=0;

            frame[j]=pages[i];
            break;
        }
        if(count[least]>count[frame[j]])
        {
            least=frame[j];
        }
    }
    if(flag)
    {
        minTime=50;
        for(j=0;j<f;j++)
        {
            if(count[frame[j]]==count[least] && time[frame[j]]<minTime)
            {
                temp=j;
                minTime=time[frame[j]];
            }
        }
        count[frame[temp]]=0;
        frame[temp]=pages[i];
    }
    for(j=0;j<f;j++)
    {
        printf("%d ",frame[j]);
    }
    printf("\n");
}

printf("Page hit = %d\n",hit);
int fault= (p-hit);
printf("Page fault = %d\n",fault);
return 0;
}
