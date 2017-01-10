//
//  11656.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 4..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
    string str;
    cin >> str;
    
    vector<string> v;
    //cout << "str size: " << str.size() << '\n';
    int size = str.size();
    for(int i=0; i<size; i++){
        //cout <<"i:"<< i<<","<< str << '\n';
        v.push_back(str);
        str.erase(0,1);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }
}
