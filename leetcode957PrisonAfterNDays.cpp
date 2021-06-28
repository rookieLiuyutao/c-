//
// Created by 95853 on 2021/6/27.
//
#include "iostream"
#include "algorithm"
#include "cstring"
#include "vector"
using namespace std;

int get(int state){
    int res = 0;
    for(int i = 7; i >=0; i--) {
      res<<=1;
        if (i&&i<7){
            if ((state>>(i-1)&1)==(state>>(i+1)&1)){
                res++;
            }
        }
    }
    return res;
}

vector<int > outPut(int state){
    vector<int >res;
    for(int i = 7; i >=0; i--) {
      res.push_back(state>>i&1);
    }
    return res;
}

vector<int> prisonAfterNDays(vector<int>& cells, int n) {
    int state = 0;
    for(auto i:cells){
        state = state*2+i;
    }

    vector<int> f(256,-1);
    f[state] = 0;
    for(int i = 1; n; i++) {
      int next = get(state);
      n--;
        if (f[next]!=-1){
            n%=i-f[next];
        } else{
            f[next] = i;
        }
        state = next;
    }
    return outPut(state);


}



int main(){

}