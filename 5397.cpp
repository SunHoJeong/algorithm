//
//  5397.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 15..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>

using namespace std;

queue<char> left_q;
queue<char> right_q;

int main(){
    int n;
    cin >> n;
    
    while(n--){
        string str;
        cin >> str;
        
        for(int i=0; i<str.size(); i++){
            if(str[i] == '<'){
                if(!right_q.empty()){
                    char temp = right_q.front();
                    right_q.pop();
                    left_q.push(temp);
                }
            }
            else if(str[i] == '>'){
                if(!left_q.empty()){
                    char temp = left_q.front();
                    left_q.pop();
                    right_q.push(temp);
                }
            }
            else if(str[i] == '-'){
                if(!left_q.empty()){
                    left_q.pop();
                }
            }
            left_q.push(str[i]);
        }
        
        
    }
}
