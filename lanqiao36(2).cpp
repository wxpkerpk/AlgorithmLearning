#include<iostream>
#include<stack>
#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string.h>
#include<algorithm>
#define N 10005
#define INF 0x3f3f3f
struct node
{
    int data ;
    struct node *next ;
}tab[N];
struct node vist2[N];
struct node vist3[N];
int cnt ;
int x=0;
int y=0;
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
void bfs2(struct node b){
    if(b.next==NULL){
        return ;
    }
    vist2[x++]=b;
}
void bfs3(int x){
    if(vist2[x].next==null){
        return ;
    }
    vist3[x]=*vist2[x].next;
}
void bfs4(int x){

}
