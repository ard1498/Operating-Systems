#include<iostream>
#include<cstdlib>
#include<pthread.h>
#include<windows.h>

using namespace std;

#define NUM_THREADS 5

void *PrintHello(void* threadid){
    long tid;
    tid = (long)threadid;
    cout<<"\nHello world from thread id :"<<tid<<"\n";
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    int rc;
    for(int i = 0;i < NUM_THREADS; i++){
        cout<<"\ncreating threads : "<<i<<"\n";
        rc = pthread_create(&threads[i],NULL,PrintHello,(void*)i);

        if(rc){
            cout<<"\nError Unable To Open.."<<rc<<"\n";
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}