#include<sys/ipc.h>
#include<sys/shm.h>
#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

//shmat,shmdt,shmid,shmctl,ftok,key,shmget

int main(){
    key_t key = ftok("shmpart",65);
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    char* str = (char*) shmat(shmid,(void*)0,0);
    cout<<"\nreading from shared file data:"<<str<<"\n";
    shmdt(str);
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
} 