//
//  10828.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2016. 12. 31..
//  Copyright © 2016년 수노. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    int n;
    string cmd;
    stack<int> stack;
    
    cin >> n;
    
    for(int i =0; i<n; i++){
        cin >>cmd;
        if(cmd == "push"){
            int num;
            cin >> num;
            stack.push(num);
        }
        else if(cmd == "pop"){
            cout << (stack.empty() ? -1 : stack.top()) << '\n';
            if(!stack.empty()){
                stack.pop();
            }
        }
        else if(cmd == "size"){
            cout << stack.size() << '\n';
        }
        else if(cmd == "empty"){
            cout << (stack.empty() ? 1 : 0) << '\n';
        }
        else if(cmd == "top"){
            cout << (stack.empty() ? -1 : stack.top()) << '\n';
        }
    }
    
    
    
    return 0;
}
