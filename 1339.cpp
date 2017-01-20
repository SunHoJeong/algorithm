//
//  1339.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 18..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool check[10] = {false,};

int main(){
    int n;
    cin >> n;
    
    vector<string> v(n);
    
    while(n--){
        string str;
        cin >> str;
        v.push_back(str);
    }
}
