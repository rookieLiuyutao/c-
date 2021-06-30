//
// Created by 95853 on 2021/6/28.
//
#include "string"
#include "queue"
#include "cstdlib"
#include "cstring"
#include "algorithm"
#include "iostream"
#include "vector"
#include "deque"
using namespace std;

int main(){
    queue<int > queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    vector<int > arr;
    while (!queue.empty()){
        cout<<queue.front();
        queue.pop();
    }
    deque<int> deque;
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    while (!deque.empty()){
        cout<<deque.back()
    }
}
