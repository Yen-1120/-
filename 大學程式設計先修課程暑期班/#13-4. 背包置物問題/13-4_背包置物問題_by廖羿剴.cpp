#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    int n, today, lim, times = 0;
    string days;
    stringstream ss;
    set<int> books;
    bool visited[21];
    vector<int> booksOrder;
    vector<int> today_books;

    //input
    cin >> n;
    cin.ignore();
    getline(cin, days);
    ss << days;
    while(ss >> today){
        today_books.push_back(today);
    }
    cin >> lim;

    //processing
    if(today_books.size() > lim){
        for(int i = 0; i < lim; i++){
            books.insert(today_books[i]);
            booksOrder.push_back(today_books[i]);
        }
        for(int i = lim; i < today_books.size(); i++){
            if(books.count(today_books[i])){
                //cout << "不動\n";
                continue; //如果今天的書已經在書包
            }
            set<int> check_bag = books;
            int choice = 0;
            for(int s = i + 1; s < today_books.size() && choice < lim - 1; s++){
                if(books.count(today_books[s]) && check_bag.count(today_books[s])){
                    choice++;
                    check_bag.erase(today_books[s]);
                }
            }
            vector<int> book_No(check_bag.begin(), check_bag.end());
            //cout << "取" << book_No[0] << "放" << today_books[i] << "\n";
            books.erase(book_No[0]);
            books.insert(today_books[i]);
            times++;
        }
    }
    
    //output
    cout << times;
}