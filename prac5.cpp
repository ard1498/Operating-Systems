#include<iostream>
#include<vector>
#include<string>

using namespace std;

class pro{
    public:
    string pname;
    int Bu;
    int Ar;
    int turnaround;
    int waittime;
};

void fcfs(pro *p,int n)
{
    int i,j,temp, temp1;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(p[i].Ar>p[j].Ar)
            {
                swap(p[i],p[j]);
            }
        }
    }
}

int bursttimes(pro *p,int n){
    int flag;
    for(int i=1 ;i<=n;i++){
        if(p[i].Bu != 0){
            flag =0;
            break;
        }
    }
    return flag;
}

void roundrobin(pro *p,int Quantum,int n){
    vector<string> p2;
    int m;
    fcfs(p,n);
    for(int i=1 ;i<=n;i++)
    {
        m = Quantum;
        if(p[i].Bu > 0)
            if(p[i].Bu > Quantum){
                p[i].Bu -= Quantum;
            }
        if(bursttimes == 0)
            if(i == n)
            {
                i = 1;
                cout<<"\nj\n";
                continue;
            }
        p2.push_back(p[i].pname);
    }

    cout<<"\n round robin algorithm:\n ";
    for(int i = 0 ;i<p2.size();i++)
    {
        cout<<p2[i];
    }
}

int main(){
    int ch,n,quantum;
    int i;
    cout<<"\n Enter the number of processes: ";
    cin>>n;
    pro *p = new pro[n+1];
    for(i=1;i<=n;i++)
    {
        cout<<"\n\n Enter the process name: ";
        cin>>p[i].pname;
        cout<<"\n Enter The BurstTime for Process "<<p[i].pname<<"= ";
        cin>>p[i].Bu;
        cout<<"\n Enter the Arrival Time for Process  =  "<<p[i].Ar;
        cin>>p[i].Ar;
    }
    cout<<"\n Enter quantum value:";
    cin>>quantum;
    roundrobin(p,quantum,n);
}