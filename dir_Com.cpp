#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<errno.h>

using namespace std;

int main(int c , char*v[])
{
    DIR *mydirect;
    struct dirent *myfile;

    if(c == 2) {
        mydirect = opendir(v[1]);
        if(mydirect){
            cout<<"\nok the directory is opened.";
            while((myfile = readdir(mydirect)))
                cout<<myfile->d_name<<"\n";

            //closedir

            if(closedir(mydirect) == 0)
                cout<<"the directory is now closed.";
            else
                cout<<"the directory can not be closed.";
        }
    }

    return 0;
}