#include<iostream>
#include<string>

const static int Max = 100,framesize = 4;

using namespace std;

struct pageinput{
    int pageno;
    string pagecontent[4];
};

int main(){
    string physicalmemory[Max];
    int frameno,pageno,noofpages;
    int pagetable[Max][2];
    pageinput pi[Max];

    cout<<"\nenter no of pages :";
    cin>>noofpages;

    for(int i =0 ;i< noofpages;i++){
        cout<<"\nenter page :"<<i;
        pi[i].pageno=i;
        pagetable[i][0]= pi[i].pageno;
        for(int j =0;j<4;j++){
            cout<<"\nenter page content at "<<j<<":";
            cin>>pi[i].pagecontent[j];
        } 
    }

    for(int i =0 ;i < noofpages;i++){
        pagetable[i][1] = i % noofpages; 
    }

    cout<<"\n";

    for(int i = 0 ; i< noofpages ; i++){
        int f = pagetable[i][1];
        for(int j =0;j<4;j++){
            physicalmemory[ (f * framesize) + j ] = pi[i].pagecontent[j];
            cout<<"\n pagecontent is stored at address : "<<(f * framesize) + j<<"\n";
        }
    }

    cout<<"\nphysical memory is :\n";

    for(int i =0 ;i < (noofpages * 4);i++){
        cout<<i<<"  :  "<<physicalmemory[i]<<"\n";
    }

    return 0;
}