#include<unistd.h>
#include<iostream>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<string>
extern int errno;
using namespace std;

int main()
{
    int fd = open("foo.txt",O_WRONLY|O_CREAT|O_TRUNC,0),sz;
    if(fd == -1)
    {
        cout<<"\nerror number is:"<<errno;
        perror("PROGRAM");
    }
    sz = write(fd,"hello\n",strlen("hello\n"));
    cout<<"\n"<<sz;
    close(fd);
    char* c = (char*)calloc(100,sizeof(char));
    fd = open("foo.txt",O_RDONLY|O_CREAT,0);
    sz = read(fd,c,10);
    cout<<"\nsz in read is:"<<sz;
    cout<<"\nthose bytes are:"<<c;
    close(fd);
    return 0;
}