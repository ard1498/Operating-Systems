#include<unistd.h>
#include<sys/wait.h>//for wait(NULL)
#include<stdlib.h>//for exit()
#include<iostream>

using namespace std;

int main()
{
    fork();
    pid_t cpid;
    if(fork == 0){
        exit(0);
    }
    else{
        cpid = wait(NULL);
    }
    cout<<"\nparent id is :"<<getpid();
    cout<<"\nchild id is :"<<cpid;

    return 0;
}