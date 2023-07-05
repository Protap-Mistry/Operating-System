#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int main()
{
    int n, process[MAX], burst_time[MAX], waiting_time[MAX], turned_around_time[MAX];
    double avg_waiting_time= 0, avg_turned_around_time= 0;

    cout<<"Given number of process(es): ";
    cin>>n;
    cout<<endl<<"Given number of burst time for each process:"<<endl<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<"Process["<<i+1<<"]: ";
        cin>>burst_time[i];
        process[i]= i+1;
    }

    waiting_time[0]= 0;

    for(int i=1; i<n; i++)
    {
        waiting_time[i]= 0;
        for(int j=0; j<i; j++)
        {
            waiting_time[i]= waiting_time[i]+ burst_time[j];
        }
    }

    cout<<endl<<"Process(es)\tBurst time\tWaiting time\tTurned around time"<<endl<<endl;

    for(int i=0; i<n; i++)
    {
        turned_around_time[i]= burst_time[i]+waiting_time[i];
        avg_waiting_time= avg_waiting_time+waiting_time[i];
        avg_turned_around_time= avg_turned_around_time+turned_around_time[i];

        cout<<"Process["<<process[i]<<"]: "<<"\t\t"<<burst_time[i]<<"\t\t"<<waiting_time[i]<<"\t\t"<<turned_around_time[i]<<endl;
    }

    avg_waiting_time=avg_waiting_time/n;
    avg_turned_around_time= avg_turned_around_time/n;

    cout<<endl<<"Average waiting time: "<<avg_waiting_time<<endl;
    cout<<"Average turned around time: "<<avg_turned_around_time<<endl<<endl;

    return 0;
}
