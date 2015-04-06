#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100010 //��֪nΪ�����㶨���˸������Զ������Ҳ����������vector����
#define LL long long

int n;
LL Dp[MAXN],Max[MAXN],ans;//ȫ�������Զ���ʼ��Ϊ0

//��ʽǰ����
int head[MAXN],m=1;//��Ϊhead[]��Ԫ�ض�Ϊ0������m��1�����Ͳ��ó�ʼ��head[]��
struct Edge{
    int to,next,w;
}e[MAXN];

//��ʽǰ������ӱ�
void add_edge(int u,int v,int w){
    e[m].to = v;
    e[m].w = w;
    e[m].next = head[u];
    head[u] = m++;
}


bool f[MAXN];//��ǽڵ��Ƿ��ѱ����ʹ�
void dfs(int s){
    int k = head[s];
    while(k > 0){
        int t = e[k].to;//tΪs�ĺ��ӽڵ�
        if(!f[t]){
            f[t] = true;
            dfs(t);
            Max[s] = max(Max[s] , Dp[s] + Dp[t]+e[k].w);//��sΪ���ڵ�������� ����s�������������
            Dp[s] = max(Dp[s] , Dp[t]+e[k].w);//s��Ҷ�ӽڵ�������
        }
        k = e[k].next;
    }
    ans=max(ans,Max[s]);
}


void work(){
    f[1]=true;
    dfs(1);//�Խڵ�1Ϊ���ڵ����� ������ǰ���1������
    printf("%I64d\n",ans*(21+ans)/2);
}


void init(){
    scanf("%d",&n);
    int p,q,d;
    for(int i = 1 ; i < n ; i++){
        scanf("%d%d%d",&p,&q,&d);
        add_edge(p,q,d);
        add_edge(q,p,d);//˫��߽�ͼ������dfs
    }
}


int main()
{
    init();
    work();
    return 0;
}
