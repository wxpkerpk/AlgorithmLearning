#include<iostream>
#include<stdio.h>
#include<set>
#include<map>
#include<string.h>
#include<vector>
using namespace std;
#define maxn 1000000
#define maxm 10010
#define mod 10000000
#define inf 0x3f3f3f3f
int n;
int a[maxn];
map<int,int>mp;
set<int>num;
int main(){
    int m;
    cin>>m;
    while(m--){
        mp.clear();
        num.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            num.insert(a[i]);
        }
        int l=0,r=0;
        int m=num.size();
        int cnt=0;
        int ans=n;
        while(l<n){
            while(r<n&&cnt<m){
                if(mp[a[r]]==0){
                    cnt++;
                }
                mp[a[r]]++;
                r++;
            }
            if(cnt<m)
                break;
            ans =min(ans,r-l);
            mp[a[l]]--;
            if(mp[a[l]]==0){
                cnt--;
            }
            l++;

        }
        printf("%d\n",ans);
    }
}

