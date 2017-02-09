//
//  10610.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 9..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool visited[100002];
vector<int> v;
int len = 0;

int main(){
    string str;
    cin >> str;
    len = str.size();
    cout << str.size() << "\n";
    v.resize(len);
    for(int i=0; i<str.size(); i++){
        v[i] = str[i]-'0';
    }
    
    for(auto item: v){
        cout << item << " ";
    }
    cout << "\n";
    
    return 0;
}
