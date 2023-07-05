#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int main()
{
	int n, process[MAX], arrival_t[MAX], burst_t[MAX], keep_burst_t[MAX];
    int time_quantum, remain, collect= 0, wait_time = 0, turnaround_time = 0;
    double avg_wt= 0, avg_tat= 0;

    cout<<"Give the number of process(es): ";
    cin>>n;
    remain= n;

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

    cout<<endl<<"Give the value of time quantum: ";
    cin>>time_quantum;

    for(int i=0; i<n; i++)
    {
        keep_burst_t[i]= burst_t[i];
    }

    cout<<endl<<"Process(es)"<<"\t"<<"Arrival_time"<<"\t"<<"Burst_time"<<"\t"<<"Turned_around_time"<<"\t"<<"Waiting_time"<<endl<<endl;

    for(int i=0, total=0; remain!=0;)
    {
        if(keep_burst_t[i]<=time_quantum && keep_burst_t[i]>0)
		{
			total= total+keep_burst_t[i];
			keep_burst_t[i]= 0;
			collect= 1;
		}
		else if(keep_burst_t[i]>0)
        {
            keep_burst_t[i]= keep_burst_t[i]-time_quantum;
			total= total+time_quantum;
        }
        if(keep_burst_t[i]==0 && collect==1)
		{
			remain--;

			cout<<"Process["<<process[i]<<"]: "<<"\t\t"<<arrival_t[i]<<"\t\t"<<burst_t[i]<<"\t\t"<<total-arrival_t[i]<<"\t\t\t"<<total-arrival_t[i]-burst_t[i]<<endl;
            wait_time = wait_time + total - arrival_t[i] - burst_t[i];
            turnaround_time = turnaround_time + total - arrival_t[i];

			collect= 0;
		}

		if(i == n-1)
        {
            i= 0;
        }
		else if(arrival_t[i+1] <= total)
        {
            i++;
        }
    }

    avg_wt= wait_time*1.0/ n;
    avg_tat= turnaround_time*1.0/ n;

    cout<<endl<<"Average waiting time: "<<avg_wt<<endl;
    cout<<"Average Turned around time: "<<avg_tat<<endl<<endl;

    return 0;
}
