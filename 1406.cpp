//
//  1406.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 2..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> left_stack;
stack<char> right_stack;

int main(){
    string str;
    int n;
    
    cin >> str;
    for(int i=0; i<str.size(); i++){
        left_stack.push(str[i]);
    }
    cin >> n;
    
    while(n--){
        string cmd;
        cin >> cmd;
        
        if(cmd == "L"){// <<
            if(!left_stack.empty()){
                char temp = left_stack.top();
                left_stack.pop();
                right_stack.push(temp);
            }
            
        }
        else if(cmd == "D"){// >>
            if(!right_stack.empty()){
                char temp = right_stack.top();
                right_stack.pop();
                left_stack.push(temp);
            }
            
        }
        else if(cmd == "B"){
            if(!left_stack.empty()){
                left_stack.pop();
            }
        }
        else if(cmd == "P"){
            char add_str;
            cin >> add_str;
            
            left_stack.push(add_str);
        }
    }
    
    while(!left_stack.empty()){
        right_stack.push(left_stack.top());
        left_stack.pop();
    }
    while(!right_stack.empty()){
        cout << right_stack.top();
        right_stack.pop();
    }
    cout << '\n';
    
    return 0;
}
