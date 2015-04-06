
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
using namespace std;
const int N = 3;//物品个数
const int V = 5;//背包最大容量
int weight[N + 1] = {0,3,2,2};//物品重量
int value[N + 1] = {0,5,10,20};//物品价值
int f[N+1][V+1] = {0};
int Max(int x,int y){
    return x>y?x:y;
}
int Init(){
    int i,j,k;
    memset(f,0,sizeof(f));
    for(i=1;i<=N;i++){
        for(j=weight[i];j<=V;j++){
            f[i][j]=Max(f[i-1][j],f[i][j-weight[i]]+value[i]);
        }
    }
    return f[N][V];
}
int main(){
    cout<<Init()<<endl;
    getchar();
    return 0;
}
