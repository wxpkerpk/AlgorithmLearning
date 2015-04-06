#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
using namespace std;
#define MAX 1000
#define inf 0x3f3f3f3f
int dp[MAX][MAX];
int map[MAX][MAX];
int panduan(int s,int e){
    if(s!=e&&map[s][e]==0){
        for(int k=s+1;k<=e-1;k++){
            dp[s][e]=panduan(s,k)+panduan(k,e);
        }
        return dp[s][e];
    }
    if(s!=e&&map[s][e]!=0){
        dp[s][e]=map[s][e];
    }
    return dp[s][e];
}
int jiage(int x){
    int sum=0;;
    for(int k=1;k<=x;k++){
        sum+=(k+10);
    }
    return sum;
}
int main(){
    int n,a;
    int i,j;
    cin>>n;
    a=n-1;
    while(a){
        cin>>i>>j;
        cin>>map[i][j];
        memset(dp,0,sizeof(dp));
        a--;
    }
     cout<<jiage(panduan(1,n))<<endl;
     cout<<dp[1][n]<<endl;
}
