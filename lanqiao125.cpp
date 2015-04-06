#include<iostream>
#include<string.h>
//include<map>
#include<vector>
#include<stdio.h>
using namespace std;
#define MAX 1000
#define inf 0x3f3f3f3f
int map[MAX][MAX];
char changeDir(char d,int flag){
        char s;
    if(flag==0)
    {
        if(d=='U')
        s='L';
        if(d=='L')
        s='D';
        if(d=='D')
        s='R';
        if(d=='R')
        s='U';
    }
    if(flag==1)
    {
        if(d=='U')
        s='R';
        if(d=='R')
        s='D';
        if(d=='D')
        s='L';
        if(d=='L')
        s='U';
    }
    return s;
}
int getX(char d,int x)
{
    if(d=='U')
    return x-1;
    else if(d=='D')
    return x+1;
    else
    return x;
}
int getY(char d,int y)
{
    if(d=='L')
    return y-1;
    else if(d=='R')
    return y+1;
    else
    return y;
}


void changeMap(int x,int y)
{
    if(map[x][y]==0)
    map[x][y]=1;
    else
    map[x][y]=0;
}
int main(){
    int m,n,k;
    int x,y;
        char s;
    while(scanf("%d%d",&m,&n)!=EOF){
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
        cin>>x>>y>>s>>k;
        for(;k>=1;k--){
        s=changeDir(s,map[x][y]);
        changeMap(x,y);
        x=getX(s,x);
        y=getY(s,y);
        }
        cout<<x<<' '<<y<<endl;
    }
    return 0;
}
