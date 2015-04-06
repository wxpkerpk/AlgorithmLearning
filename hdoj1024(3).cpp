#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef int64_t int64;
int64 dp[2][1000001];
int64 a[1000001];
int64 b[1000001];
int64 res;
int n,m;
int64 Max(int64 x,int64 y){
    return x>y?x:y;
}
int main(){
    while(scanf("%d%d",&m,&n)!=EOF){
        int t=1;
        res=0;
        int i,j,k;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        memset(dp,0,sizeof(dp));
        memset(b,0,sizeof(b));
        for(i=1;i<=m;i++){
            dp[t][i]=dp[1-t][i-1]+a[i];
            int64 max=dp[1-t][i-1];
            for(j=i+1;j<=n-m+i;j++){
                max=Max(max,dp[1-t][j-1]);
                dp[t][j]=Max(dp[t][j-1],max)+a[i];
            }
            t=1-t;
        }
        t=1-t;
        res=-11111111111;
        for(j=m;j<=n;j++){
            if(res<dp[t][j])
                res=dp[t][j];
        }
        printf("%I64d\n",res);
    }
    return 0;
}
