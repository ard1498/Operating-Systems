#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

int main()
{
    char fn[10] , pat[10] , temp[1000];
    FILE *fp;
    cout<<"\nenter file name:";
    cin>>fn;
    cout<<"\nEnter pattern to be searched:";
    cin>>pat;
    fp = fopen(fn,"r");
    while(!feof(fp)){
        fgets(temp,1000,fp);
        if(strstr(temp,pat))
        cout<<temp;
    }
    fclose(fp);
    return 0;
}