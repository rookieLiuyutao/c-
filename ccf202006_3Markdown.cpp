#include "bits/stdc++.h"

using namespace std;
vector<string> md;

void work_line(string str);

int work_em(string str, int k);

int work_link(string str, int k) {
    string text, link;
    for (k++; str[k] != ']'; k++) {
        //处理链接中的em
        if (str[k] == '_'){
            text+="<em>";
            k++;
            while (str[k]!='_' )text += str[k++];
            text+="</em>";
        }else text+=str[k];
    }
    //处理链接
    //跳过]和(
    for(k+=2;str[k]!=')';k++){
        link+=str[k];
    }
    cout<<"<a href=\""<< link.c_str() << "\">"<<text.c_str() << "</a>";
    return k;
}

int work_em(string str, int k) {
    cout << "<em>";

    for (k++; str[k] != '_'; k++) {
        char c = str[k];
        if (c == '[')k = work_link(str, k);
        else cout << c;
    }

    cout << "</em>";
    return k;
}


void work_line(string str) {
    int k = 0;
    while (str[k] == ' ')k++;
    //将行首的空格删掉
    str = str.substr(k);
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (c == '_')i = work_em(str, i);
        else if (c == '[')i = work_link(str, i);
        else cout << c;

    }
}

void work(int begin, int end) {

    if (md[begin][0] == '#') {
        int k = 0;
        while (md[begin][k] == '#')k++;
        cout << "<h" << k << ">";
        work_line(md[begin].substr(k));
        cout << "</h" << k << ">" << endl;
    } else if (md[begin][0] == '*') {
        cout << "<ul>" << endl;
        for (int i = begin; i <= end; i++) {
            cout << "<li>";
            work_line(md[i].substr(1));
            cout << "</li>" << endl;
        }
        cout << "</ul>" << endl;
    } else {
        cout << "<p>";
        for (int i = begin; i <= end; i++) {
            work_line(md[i]);
            if (i != end) cout << endl;
        }
        cout << "</p>"<<endl;
    }

}

int main() {
    string str;
    while (getline(cin, str)) {
        md.push_back(str);
    }

    for (int i = 0; i < md.size(); i++) {
        if (md[i].empty())continue;
        //因为连续多行输入构成一个段落
        //先把每个段落分开，单独处理
        int j = i + 1;
        while (j < md.size() && !md[j].empty())j++;

        work(i, j - 1);
        i = j - 1;
    }
}