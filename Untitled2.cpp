#include<iostream>
#include<string.h>
using namespace std;
string str1,str2;
void fan(int n){
    if(str1[n]=='*'){
        str1[n]='o';
    }
    else
        str1[n]='*';
    if(str1[n+1]=='*'){
        str1[n+1]='o';
    }
    else
        str1[n+1]='*';
}
int main(){
    int i,sum;
    while(cin>>str1>>str2){
            sum=0;
        for(i=0;i<str1.length();i++){
            if(str1[i]!=str2[i]){
                sum++;
                fan(i);
                cout<<str1<<endl;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
