#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
void fun(vector<string>item,vector<vector<string>>code1,vector<vector<string>>code2){
    map<string,int>itemmap,finalmap;
    bool visit[400]={false};
    map<string,int>::iterator mit;
    for(int i=0;i<item.size();i++){
            itemmap.insert(pair<string,int>(item[i],1));
            finalmap.insert(pair<string,int>(item[i],1));
    }
    bool IsContinue=true;
    while(IsContinue){
        IsContinue=false;
        for(int i=0;i<code1.size();i++){
            for(int j=0;j<code1[i].size();visit[i]==false;j++){
                if(itemmap.count(code1[i][j])==0){
                    break;
                }
                if(j==code1[i].size()-1){
                    IsContinue=true;
                }
            }
        }
    }
}
