//
//  9012.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2016. 12. 31..
//  Copyright © 2016년 수노. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

void check(string str){
    stack<int> stack;
    for(int i=0; i<str.size(); i++){
        if(str[i] == '('){
            stack.push(i);
        }
        else if(str[i] == ')'){
            if(!stack.empty()){
                stack.pop();
            }
            else{
                cout << "NO" << '\n';
                return;
            }
        }
    }
    
    if(stack.empty()){
        cout << "YES" << '\n';
        
    }
    else{
        cout << "NO" << '\n';
    }
}

int main(){
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        check(str);
    }
    
}
