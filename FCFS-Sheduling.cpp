#include<bits/stdc++.h>
using namespace std;
struct process
{
    int pid;
    int at;
    int bt;
    int wt;


};
bool cmp(process a,process b)
{
    return a.at<b.at;
}
int main()
{
    queue<int>q;
    freopen ("fcfs.txt","r",stdin);
    //freopen ("fcfsout.txt","w",stdout);
    int n;
    vector<process>v;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        process temp;
        temp.pid=i;
        cin>>temp.at>>temp.bt;
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),cmp);
    int time = 0, idl = 0, x = 0;
    for (int i = 0; i<v.size(); i++)
    {
        q.push(i);

    }

    while (!q.empty())
    {
        int k = q.front();

        if (time >= v[k].at)
        {
            v[k].wt = time - v[k].at;
            //cout << v[k].wt << endl;
            time += v[k].bt;
            q.pop();
        }
        else {
            time++;
            idl++;
        }
    }

    double twt=0;
    for(int i=0;i<v.size();i++)
    {

        twt+=v[i].wt;
    }
    double cpuUtil=(double)((time-idl)/(double)time)*100.0;



    cout<<"Process ID-----Arrival Time---Duration-----Waiting Time\n";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].pid<<"\t\t "<<v[i].at<<" \t\t"<<v[i].bt<<"\t\t"<<v[i].wt<<endl;
    }

    cout<<"Avarage Waiting Time = "<<(float)((float)twt/(float)n)<<endl;

    cout<<"CPU utilization = "<<cpuUtil<<"\%"<<endl;


    return 0;
}
