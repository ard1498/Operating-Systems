#include<iostream>
#include<unistd.h>
#include<thread>
#include<time.h>

using namespace std;

const int buffmax = 25;
int sharedbuffer[25];
int fullindex = 0;
int freeindex = 0;

void producer(){
    int nextproduced = 25;
    while(true){
        while((freeindex+1)%buffmax == fullindex){
            cout<<"\noverflow";
            sleep(1);
        }
        sharedbuffer[freeindex] = nextproduced;
        cout<<"\nProduced item at position"<<freeindex;
        sleep(1);
        freeindex = (freeindex+1)%buffmax;
    }
}

void consumer(){
    int nextconsumed = 0;
    while(true){
        while(freeindex == fullindex){
            cout<<"\nunderflow...";
            sleep(1);    
        }
        nextconsumed = sharedbuffer[fullindex];
        cout<<"\nConsumed at position "<<fullindex;
        sleep(0.5);
        fullindex = (fullindex+1)%buffmax;
    }
}

int main()
{   
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
    cout<<"\ncompleted";
    return 0;
}