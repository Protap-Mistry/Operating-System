#include <bits/stdc++.h>
using namespace std;

int main()
{

    int processes, resources;

    cout<<"Give the number of process(es): ";
    cin>>processes;
    cout<<"Give the number of resource(s): ";
    cin>>resources;

    int allocation[processes][resources];

    cout<<endl<<"Enter allocated resource values by one space: "<<endl;
    for (int i = 0; i < processes; i++)
    {
        cout<<"Process["<<i+1<<"]: ";
        for (int j = 0; j < resources; j++)
        {
            cin>>allocation[i][j];
        }
    }

    int maximum[processes][resources];

    cout<<endl<<"Enter maximum Resource values by one space: "<<endl;
    for (int i = 0; i < processes; i++)
    {
        cout<<"Process["<<i+1<<"]: ";
        for (int j = 0; j < resources; j++)
        {
            cin>>maximum[i][j];
        }
    }

    int available[resources];

    cout<<endl<<"Enter available resource values by one space: ";
    for (int i = 0; i < resources; i++)
    {
        cin>>available[i];
    }

    int finish[processes], ans[processes], val = 0;

    for (int k = 0; k < processes; k++)
    {
        finish[k] = 0;
    }

    int need[processes][resources];

    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    for (int k = 0; k < processes; k++)
    {
        //bool canAllocate=false;
        for (int i = 0; i <processes; i++)
        {
            if (finish[i] == 0)
            {
                int flag = 0;
                for (int j = 0; j < resources; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[val++] = i;
                    for (int y = 0; y < resources; y++)
                    {
                        available[y] += allocation[i][y];
                    }
                    finish[i] = 1;
                    //canAllocate=true;
                }
            }
        }
        /*if(canAllocate==false)
        {
            cout<<"System is not safe"<<endl;
            continue;
        }*/
    }

    cout << endl<<"Following is the safe sequence: ";
    for (int i = 0; i < processes - 1; i++)
    {
        cout << " P" << ans[i] << " ->";
    }
    cout << " P" << ans[processes - 1] <<endl;

    return 0;
}

