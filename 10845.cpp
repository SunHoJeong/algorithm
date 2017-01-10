//
//  10845.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 3..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
    queue<int> queue;
    int n;
    cin >> n;
    
    while(n--){
        string cmd;
        cin >> cmd;
        
        if(cmd == "push"){
            int num;
            cin >>num;
            queue.push(num);
            
        }
        else if(cmd == "pop"){
            if(!queue.empty()){
                int temp = queue.front();
                queue.pop();
                cout << temp << '\n';
            }
            else{
                cout << -1 << '\n';
            }
            
        }
        else if(cmd == "size"){
            cout << queue.size() << '\n';
        }
        else if(cmd == "empty"){
            if(queue.empty()){
                cout << 1 << '\n';
            }
            else{
                cout << 0 << '\n';
            }
            
        }
        else if(cmd == "front"){
            if(!queue.empty()){
                cout << queue.front() << '\n';
            }
            else{
                cout << -1 << '\n';
            }
        }
        else if(cmd == "back"){
            if(!queue.empty()){
                cout << queue.back() << '\n';
            }
            else{
                cout << -1 << '\n';
            }
        }
    }
}
