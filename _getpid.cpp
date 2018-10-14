#include<unistd.h>
#include<iostream>

using namespace std;

int main()
{
    int pid = fork();
    if(pid ==0)
    {
        cout<<"\n parent is represented.";
        cout<<"\n getppid(return parent's process id) is:"<<getppid();
        cout<<"\n getpid(returns process id) is:"<<getpid();
    }
    else{
        cout<<"\nchild is represented.";
        cout<<"\n getppid(return parent's process id) is:"<<getppid();
        cout<<"\n getpid(returns process id) is:"<<getpid();
    }
    return 0;
}
