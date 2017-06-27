//
//  2644.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 6. 27..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;
int main(){
    int n;
    int st, des;
    int m;
    bool visited[101] = {false,};
    int result[101];
    bool find = false;
    
    cin >> n;
    cin >> st >> des;
    vector<int> v[n+1];
    cin >> m;
    
    for(int i=1; i<=m; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        v[temp1].push_back(temp2);
        v[temp2].push_back(temp1);
    }
    
    q.push(st);
    visited[st] = true;
    result[st] = 0;
    
    while(!q.empty()){
        int start = q.front();
        q.pop();
        
        if(start == des){
            find = true;
            break;
        }
        
        for(int a : v[start]){
            if(!visited[a]){
                q.push(a);
                visited[a] = true;
                result[a] = result[start] + 1;
            }
        }
    }
    
    if(find){
        cout << result[des] << "\n";
    }
    else{
        cout << -1 << "\n";
    }
    
    return 0;
}
