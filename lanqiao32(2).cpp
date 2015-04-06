#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100010 //不知n为多大，随便定义了个，可以定义更大，也可以想想用vector容器
#define LL long long

int n;
LL Dp[MAXN],Max[MAXN],ans;//全区变量自动初始化为0

//链式前向星
int head[MAXN],m=1;//因为head[]中元素都为0，所以m从1计数就不用初始化head[]了
struct Edge{
    int to,next,w;
}e[MAXN];

//链式前向星添加边
void add_edge(int u,int v,int w){
    e[m].to = v;
    e[m].w = w;
    e[m].next = head[u];
    head[u] = m++;
}


bool f[MAXN];//标记节点是否已被访问过
void dfs(int s){
    int k = head[s];
    while(k > 0){
        int t = e[k].to;//t为s的孩子节点
        if(!f[t]){
            f[t] = true;
            dfs(t);
            Max[s] = max(Max[s] , Dp[s] + Dp[t]+e[k].w);//以s为根节点的子树中 经过s的最大两点间距离
            Dp[s] = max(Dp[s] , Dp[t]+e[k].w);//s到叶子节点的最长距离
        }
        k = e[k].next;
    }
    ans=max(ans,Max[s]);
}


void work(){
    f[1]=true;
    dfs(1);//以节点1为根节点深搜 ，深搜前标记1被访问
    printf("%I64d\n",ans*(21+ans)/2);
}


void init(){
    scanf("%d",&n);
    int p,q,d;
    for(int i = 1 ; i < n ; i++){
        scanf("%d%d%d",&p,&q,&d);
        add_edge(p,q,d);
        add_edge(q,p,d);//双向边建图，方便dfs
    }
}


int main()
{
    init();
    work();
    return 0;
}
