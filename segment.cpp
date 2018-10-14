#include<iostream>
#include<string>

using namespace std;

const int Max = 100;

struct segment{
    int segmentno;
    int segmentsize;
    string content[Max];
};

struct segmenttable{
    segment seg;
    int baseaddress;
};

int main(){
    segmenttable st[Max];
    int noofsegments,size;
    string physicalmemory[Max];
    int addindex = 0;

    cout<<"\nenter the no of segments : ";
    cin>>noofsegments;

    for(int i =0;i<noofsegments;i++){
        st[i].seg.segmentno = i; 
        st[i].baseaddress = addindex;
        
        cout<<"\nenter "<<i<<"'s segment content size:";
        cin>>size;
        st[i].seg.segmentsize = size;

        cout<<"\nenter "<<i<<"'s segment content(s):";
        for(int j =0;j<size;j++){
            cin>>st[i].seg.content[j];
        }
        addindex += size;
    }

    for(int i = 0 ; i < noofsegments ; i++){
        for(int j = 0 ; j < st[i].seg.segmentsize ; j++){
            physicalmemory[st[i].baseaddress + j] = st[i].seg.content[j];
        }
    }

    cout<<"\n physical memory : \n";
    for(int i = 0 ; i < addindex;i++){
        cout<<"index "<<i<<" : "<<physicalmemory[i]<<"\n";
    }

    return 0;
}