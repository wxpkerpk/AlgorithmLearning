#include<iostream>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
using namespace std ;
const int N=10005 ;
struct node
{
    int data ;
    struct node *next ;
}tab[N];
int vist[N];
int cnt ;

void add(int a,int b)
{
      struct node *q=&tab[a];
      while( q->next != NULL)
      {
           q = q->next ;
      }
      struct node *s ;
      s = (struct node *)malloc(sizeof(struct node)) ;
      q->next =s ;
      s->data =b;
      s->next =NULL ;
}

void dfs(int x,int n,int s)
{
        vist[x]=1;
        struct node *q=&tab[x];
        if(n>=3)
        {
            cnt++;
            return ;
        }
        while( (q=q->next) !=NULL)
        {
               int w=q->data;
          if( vist[w]!=1 ||( w == s && n==2 ))
               {
                    dfs(w,n+1,s);
                    if( w != s )
                        vist[w]=0;
               }
        }
}

int main()
{
      int n,m,a,b;
      scanf("%d%d",&n,&m);
      for(int i = 1 ; i <= n ; i++ )
      {
            tab[i].data = i ;
            tab[i].next = NULL ;
      }
      while(m--)
      {
              scanf("%d%d",&a,&b);
              add(a,b);
              add(b,a);
      }
      cnt = 0 ;
      for(int i = 1 ; i <= n ; i++)
      {
             memset(vist,0,sizeof(vist));
             dfs(i,0,i);
      }
      printf("%d\n",cnt);
      return 0;
}
