
#include<stdio.h>
#include<string.h>

int a[201][101][101];
int map[101][101];

int max(int n1,int n2,int n3,int n4)
{
   int s,d;
   s = n1>n2?n1:n2;
   d = n3>n4?n3:n4;
   s = s>d?s:d;
   return s;
}

int slove(int m,int n)
{
  int x1,y1,x2,y2,k;
  for(k=2;k<=m+n;k++)
   for(x1=1;x1<=m;x1++)
    for(x2=1;x2<=m;x2++)
     {
       y1=k-x1;
       y2=k-x2;
       if(y1<0 || y2<0 || y1>n || y2>n)continue;
       if(y1==y2)continue;
       a[k][x1][x2]=max(a[k-1][x1][x2],a[k-1][x1-1][x2],
                        a[k-1][x1][x2-1],a[k-1][x1-1][x2-1])
                        +map[x1][y1]+map[x2][y2];
     }
   return a[m+n-1][m][m-1];
}

int main()
{
  int t,m,n,i,j;
  scanf("%d",&t);
  while(t--)
  {
    memset(a,0,sizeof(a));
    printf("%d",a);
    getchar();
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;++i)
     for(j=1;j<=n;++j)
      scanf("%d",&map[i][j]);
    printf("%d\n",slove(m,n));
  }
  return 0;
}
