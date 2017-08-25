
#include<bits/stdc++.h>


using namespace std;
struct process
{
    int pid;
    int at;
    int bt;
    int wt;
    bool flag;


};
bool cmp(process a, process b)
{
    return a.bt<b.bt;
}
bool cmp2(process a, process b)
{
    return a.at<b.at;
}
int main()
{
    queue<int>q;
    freopen ("sjfs.txt","r",stdin);
    //freopen ("fcfsout.txt","w",stdout);
    int n;
    vector<process>v;
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        process temp;
        temp.pid = i;
        temp.flag = false;
        cin >> temp.at >> temp.bt;
        v.push_back(temp);

    }
    int time = 0;
    int idl = 0;
    int cou = 0, x = 0;
    sort(v.begin(), v.end(), cmp);

    vector<process>ans;
    while (cou < n)
    {
        vector<process>tem;
        for (int i = 0; i<n; i++)
        {
            if (v[i].at <= time&&!v[i].flag)
            {
                //cout<<v[i]<<endl;
                v[i].flag = true;
                tem.push_back(v[i]);
                break;


            }

        }


        if (tem.size() == 0)
        {
            idl++;
            time++;

        }
        else
        {
            tem[0].wt = time - tem[0].at;
            time += tem[0].bt;
            ans.push_back(tem[0]);
            cou++;

        }

    }
    double totalWt=0;
    for (int i = 0; i<ans.size(); i++)
    {
        totalWt+=ans[i].wt;


    }
    cout<<"\nProcess ID == Arival Time == Wait Time\n\n";
    for(int i=0;i<n;i++)
    {
        cout<<ans[i].pid<<"\t\t"<<ans[i].at<<"\t\t"<<ans[i].wt<<endl;
    }
    cout<<"\nAvg wait Time= "<<totalWt/(double)n<<endl;
    cout<<"Cpu Utilizatimon= "<<(double)((double)(time-idl)/(double)time)*100<<"\%"<<endl;

    //cout<<time<<endl;

    return 0;
}
