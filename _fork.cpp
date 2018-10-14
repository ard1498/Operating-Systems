#include<unistd.h>
#include<iostream>

using namespace std;

int main()
{
    /*
    int id = fork();
    if(id == 0)
        cout<<"in child process.\n";
    else
        cout<<"in parent process.\n";
    */

    fork();
    fork();
    fork();

    cout<<"\nhello world....!1!1\n";
    return 0;
}
