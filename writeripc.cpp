#include<sys/ipc.h>
#include<sys/shm.h>
#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

//shmat,shmdt,shmid,shmctl,ftok,key,shmget

int main(){
    //first we generate a unique key for shared memory
    key_t key = ftok("shmpart",65);
    
    //getting an id to identify shared segment
    int shmid = shmget(key,1024,0666|IPC_CREAT);

    //now to get attached to shared memory
    char* str = (char*) shmat(shmid,(void*)0,0);
    cout<<"\nwriter write:";
    cin>>str;
    cout<<"\ndatawriiten is :"<<str<<"\n";
    shmdt(str);
    return 0;
}
