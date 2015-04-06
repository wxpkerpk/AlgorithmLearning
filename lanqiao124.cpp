#include<iostream>
#include<fstream>
#include<memory.h>
using namespace std;
int a[100];
int ok(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(a[i]!=a[i-1])
            return 0;
    }
    return 1;

}
int main(void)
{
    int n;
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        int count=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        while(!ok(n))
        {
        int t;
        for(int i=1;i<=n;i++)
        {
            if(i==1)
            {
                t=a[i]/2;
                a[i]=t;
            }
           else
           {
                a[i-1]+=a[i]/2;
                a[i]/=2;
           }
        }
        a[n]+=t;
        for(int i=1;i<=n;i++)
           {
               if(a[i]%2)
               {
                   a[i]++;
                   count++;
               }
           }
        }
        cout<<count<<endl;
    }

    return 0;
}
