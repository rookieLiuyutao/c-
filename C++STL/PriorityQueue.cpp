//
// Created by 95853 on 2021/10/12.
//
#include <functional>
#include "iostream"
#include "queue"
#include "vector"
#include "cstring"
using namespace std;
struct User{
    int id{};
    int score{};
    string name;
    int win_count{};
    int pass_time{};
}user;


auto cmp = [](const User & a,const User & b){return a.score < b.score;};
struct Task{
    priority_queue<User,vector<User>, decltype(cmp)> q;
    string type;
};

int main(){

    vector<Task>tk;
    for(int i = 0; i <10; i++) {

    }
    for(int i = 0; i <10; i++) {

    }
}