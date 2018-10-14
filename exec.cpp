#include<unistd.h>
#include<iostream>
//#include<string>

using namespace std;

int main()
{
    char* args[]={"./_fork",NULL};
    execvp(args[0],args);
    cout<<"\n";
}