//
//  5014.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 20..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
bool visited[1000001];
int value[1000001];
int f, start, goal, up, down;
bool flag = false;
int ans = 0;

void stair(){
    while(!q.empty()){
        int st = q.front();
        q.pop();
        
        if(st == goal){
            ans = value[st];
            flag = true;
            return;
        }
        
        int temp = st+up;
        if(temp <= f && !visited[temp]){
            q.push(temp);
            visited[temp] = true;
            value[temp] = value[st]+1;
            //cout << temp << ","<< value[temp] <<"\n";
        }
        
        temp = st-down;
        if(0 < temp && !visited[temp]){
            q.push(temp);
            visited[temp] = true;
            value[temp] = value[st]+1;
            //cout << temp << "," << value[temp]<< "\n";
        }
    }
}

int main(){
    
    cin >> f >> start >> goal >> up >> down;
    
    value[start] = 0;
    visited[start] = true;
    q.push(start);
    stair();

    if(flag){
        cout << ans << "\n";
    }
    else{
        cout << "use the stairs" << "\n";
    }
    return 0;
}
