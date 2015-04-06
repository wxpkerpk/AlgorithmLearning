#include<iostream>
#include<string>
#include<vector>
#include<string>
#include<vector>
using namespace std;
struct Review{
    std::string title;
    int rating;
};
bool FillReview(Review &rr);
void ShowReview(const Review &rr);
int main(){
    vector<Review> books;
    Review temp;
    while(FillReview(temp)){
        books.push_back(temp);
        int num=books.size();
        if(num>0){
            cout<<"Thank You.You Entered the following:\n"<<"Rating\tbook\n";
            for(int i=0;i<num;i++)
                ShowReview(books[i]);
            cout<<"Reprising:\n"<<"Rating\tBook\n";
            vector<Review>::iterator pr;
            for(pr=books.begin();pr!=books.end();pr++){
                ShowReview(*pr);
            }
            vector<Review> oldlist(books);
            if(num>3){
                books.erase(books.begin())+1,books.begin()+3);
                cout<<"After erasure:\n";
                for(pr=books.begin();pr!=books.end();pr++)
                    ShowReview(*pr);
                books.insert(books.begin(),oldlist.begin()+1,oldlist.begin()+2)
            }
        }
    }
}
