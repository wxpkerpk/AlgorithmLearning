#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define MIN 0x800000000
#define N 1000001
int a[N],b[N],dp[N];
int main(){
    int n,m,i,j,max;
    while(scanf("%d%d",&m,&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        memset(b,0,sizeof(b));
        for(i=1;i<=m;i++){
            max=MIN;
            for(j=i;j<=n;j++){
                if(dp[j-1]>b[j-1]){
                    dp[j]=dp[j-1]+a[j];
                }
                else{
                    dp[j]=b[j-1]+a[j];
                }
                b[j-1]=max;
                if(max<dp[j])
                    max=dp[j];
            }
            b[j-1]=max;
        }
        printf("%d\n",max);
    }
    return 0;
}
