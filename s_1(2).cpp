//
//  s_1(2).cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 6. 30..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    int t=0;
    cin >> t;
    
    for(int k=1; k<=t; k++){
        int answer = 0;
        int cnt = 0;
        string input;
        cin >> input;
        stack<char> s;
        
        for(int i=0; i<input.size(); i++){
            cout << input[i] <<"\n";
            if(input[i] == '(' || input[i] == '{' || input[i] == '['){
                s.push(input[i]);
            }
            else if(input[i] == ')'){
                if(s.top() == '('){
                    cnt += 2;
                    s.pop();
                }
                else{
                    if(answer < cnt ){
                        answer = cnt;
                    }
                    cnt = 0;
                }
            }
            else if(input[i] == '}'){
                if(s.top() == '{'){
                    cnt += 2;
                    s.pop();
                }
                else{
                    if(answer < cnt ){
                        answer = cnt;
                    }
                    cnt = 0;
                }
            }
            else if(input[i] == ']'){
                if(s.top() == '['){
                    cnt += 2;
                    s.pop();
                }
                else{
                    if(answer < cnt ){
                        answer = cnt;
                    }
                    cnt = 0;
                }
            }
            
        }
        if(answer < cnt ){
            answer = cnt;
        }
        cnt = 0;
        
        cout << "Case #"<< k <<"\n";
        cout << answer <<"\n";
        
        while(!s.empty()){
            s.pop();
        }
        
    }
    return 0;
}
