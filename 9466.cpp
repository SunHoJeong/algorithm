//
//  9466.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 31..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stack>

using namespace std;
int stu[100001];
bool visited[100001];
bool cycle[100001];
int cnt = 0;
int n;
stack<int> s;

void search(int x){
    visited[x] = true;
    
    for(int i=1; i<=n; i++){
        if(stu[x] == i){
            if(!visited[i]){
                s.push(i);
            }
            else{
                int root = i;
                bool find = false;
                while(s.empty()){
                    int temp = s.top();
                    s.pop();
        
                    if(find){
                        cnt ++;
                        cout << x << "," << i << ":" << cnt << "\n";
                    }
                    else{
                        if(temp == root){
                            cycle[temp] = true;
                            find = true;
                        }
                    }
                }
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        cin >> n;
        memset(stu, 0, sizeof(stu));
        memset(visited, false, sizeof(visited));
        memset(cycle, false, sizeof(cycle));
        
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                s.push(i);
                search(i);
            }
        }
    }
    return 0;
}
