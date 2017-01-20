//
//  5397.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 15..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> left_s;
stack<char> right_s;

int main(){
    int n;
    cin >> n;
    
    while(n--){
        string str;
        cin >> str;
        
        for(int i=0; i<str.size(); i++){
            if(str[i] == '<'){
                if(!left_s.empty()){
                    char temp = left_s.top();
                    left_s.pop();
                    right_s.push(temp);
                }
            }
            else if(str[i] == '>'){
                if(!right_s.empty()){
                    char temp = right_s.top();
                    right_s.pop();
                    left_s.push(temp);
                }
            }
            else if(str[i] == '-'){
                if(!left_s.empty()){
                    left_s.pop();
                }
            }
            else{
                left_s.push(str[i]);
            }
        }
        
        while(!left_s.empty()){
            char temp = left_s.top();
            left_s.pop();
            right_s.push(temp);
            
        }
        
        while(!right_s.empty()){
            cout << right_s.top();
            right_s.pop();
        }
        cout<<"\n";
    }
    
    return 0;
}
