#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main(){
    int T;
                int flag=0;
            int j=0;int max=0;
                 int index=-1;
                 int i;
    while(cin>>T){
        if(T==0)
            break;
        string *b=new string[T];
        string *a=new string[T];
        int *c=new int[T];
        int point=0;
        memset(c,0,sizeof(c));
        for(i=0;i<T;i++){
            cin>>b[i];
            flag=0;
            for(j=0;j<point;j++){
                if(b[i]==a[j]){
                    c[j]++;
                    flag=1;
                    break;
                }
                if(flag==0){
                    a[j]=b[i];
                    c[j]++;
                    point++;
                }

            }
        }
        max=0;
        index=-1;
        for(i=0;i<point;i++){
            if(max<c[i]){
                max=c[i];
                index=i;
            }
        }
        cout<<a[index]<<endl;
        delete[]b;
        delete[]c;
        delete[]a;

    }
    return 0;
}
