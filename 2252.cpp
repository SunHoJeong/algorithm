//
//  2252.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 9..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > v;
bool visited[32005];
int n;
int m;
vector<int> ans;

void dfs(int x){
    if(visited[x]){
        return;
    }
    visited[x] = true;
    for(int i=0; i<v[x].size(); i++){
        if(!visited[v[x][i]]){
            dfs(v[x][i]);
        }
    }
    ans.push_back(x);
    
}

int main(){
    cin >> n >> m;
    v.resize(n+1);
    for(int i=1; i<=m; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        v[temp1].push_back(temp2);
    }
    
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    
    for(int i=0; i<n; i++){
        cout << ans.back() << " ";
        ans.pop_back();
    }
    return 0;
}
