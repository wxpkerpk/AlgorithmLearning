#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int i,j=0,k;
    long long min,max,tem,ans=1;
    int single=0x03;
    while(cin>>min>>max){
        tem=max;
        ans=1;
        single=0x03;
        j=0;
        k=0;
        long long temp2=0;
        if(max!=min){
        while(tem!=0){
            tem>>=1;
            j++;

        }
        for(k=0;k<j-2;k++){
            ans<<=1;
            ans|=0x01;
        }
        if(ans<min){
                ans<<=1;
                while(ans<min&&ans<max){
                        ans^=single;
                        single<<=1;
                    }
        }
        cout<<ans<<endl;
        }
        else{
            cout<<max<<endl;
        }
    }
    return 0;
}
