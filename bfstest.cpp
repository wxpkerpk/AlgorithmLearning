#include<iostream>
#include<string.h>
#include<map>
#include<stdio.h>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#define inf 0x3f3f3f
#define MAX_N 10000
typedef pair<int,int> P;
char maze[MAX_N][MAX_N];
int N,M;
int sx,sy;
int gx,gy;
int d[MAX_N][MAX_N];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int bfs(){
    queue<P> que;
    memset(d,inf,sizeof(d));
    que.push(P(sx,sy);
    d[sx][sy]=0;
    while(que.size()){
        P p=que.front();
        que.pop();
        if(p.first==gx&&p.second==gy)
            break;
        for(int i=0;i<4;i++){
            int nx=p.first+dx[i],ny=p.second+dy[i];
            if(0<=nx&&nx<N&&0<=ny&&ny<M&&maze[nx][ny]!='#'&&d[nx][ny]==inf){
                que.push(P(nx,ny));
                d[nx][ny]=d[p.first][p.second];
            }
        }
    }
    return d[gx][gy];
}
int main(){
    cin>>N>M;
}
