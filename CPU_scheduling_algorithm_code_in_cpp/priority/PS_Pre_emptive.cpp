#include<bits/stdc++.h>
#define MAX 100
using namespace std;
/**
    The waiting time for the process having the highest priority will always be zero in preemptive mode.
**/
int main()
{
    int n, process[MAX], priority[MAX], arrival_t[MAX], burst_t[MAX], keep_burst_t[MAX], completion_t[MAX], turned_around_t[MAX], waiting_t[MAX];
    int loop_end= 0, smallest= 0, stop_when_get_zero= 0;
    double avg_wt=0, avg_tat= 0;

    cout<<"Given number of process(es): ";
    cin>>n;

    cout<<endl<<"Given number of (priority) for each process:"<<endl<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<"Process["<<i+1<<"]: ";
        cin>>priority[i];
    }

    cout<<endl<<"Given number of (arrival time) for each process:"<<endl<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<"Process["<<i+1<<"]: ";
        cin>>arrival_t[i];
    }

    cout<<endl<<"Given number of (burst time) for each process:"<<endl<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<"Process["<<i+1<<"]: ";
        cin>>burst_t[i];
        process[i]= i+1;
    }

    for(int i=0; i<n; i++)
    {
        keep_burst_t[i]= burst_t[i];
    }

    priority[MAX-1]= -1;

    for(int i=0; loop_end!=n; i++)
    {
        smallest= MAX-1;

        for(int j=0; j<n; j++)
        {
            if(arrival_t[j]<=i && priority[j]>priority[smallest] && burst_t[j]>0)
            {
                smallest= j;
            }
        }
        burst_t[smallest]--;

        if(burst_t[smallest]==0)
        {
            loop_end++;
            stop_when_get_zero= i+1;
            completion_t[smallest]= stop_when_get_zero;
            turned_around_t[smallest]= completion_t[smallest]-arrival_t[smallest];
            waiting_t[smallest]= turned_around_t[smallest]-keep_burst_t[smallest];
        }
    }

    cout<<endl<<"Process(es)"<<"\t"<<"Priority"<<"\t"<<"Arrival_time"<<"\t"<<"Burst_time"<<"\t"<<"Completion_time"<<"\t"<<"Turned_around_time"<<"\t"<<"Waiting_time"<<endl<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<"Process["<<process[i]<<"]: "<<"\t"<<priority[i]<<"\t\t"<<arrival_t[i]<<"\t\t"<<keep_burst_t[i]<<"\t\t"<<completion_t[i]<<"\t\t"<<turned_around_t[i]<<"\t\t\t"<<waiting_t[i]<<endl;
        avg_wt= avg_wt+waiting_t[i];
        avg_tat= avg_tat+turned_around_t[i];
    }

    cout<<endl<<"Average waiting time: "<<avg_wt/n<<endl;
    cout<<"Average Turned around time: "<<avg_tat/n<<endl<<endl;

    return 0;
}
