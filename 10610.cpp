//
//  10610.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 9..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool visited[100002];
vector<int> v;
int len = 0;

int main(){
    int sum = 0;
    string str;
    cin >> str;
    
    for(char c : str){
        sum += c-'0';
    }
    
    sort(str.begin(), str.end());
    
    if(str[0] == '0' && sum % 3 ==0){
        reverse(str.begin(), str.end());
        cout << str << "\n";
    }else{
        cout << -1 << "\n";
    }
    
    return 0;
}
