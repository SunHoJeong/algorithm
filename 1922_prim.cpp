//
//  1922_prim.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 12..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> P;
bool visited[1005];
vector<P> v[1005];

int main(){
    int n,m;
    cin >> n;
    cin >> m;
    
    for(int i=1; i<=m; i++){
        int f, s, w;
        cin >> f >> s >> w;
        v[f].push_back(P(s,w));
        v[s].push_back(P(f,w));
    }
    visited[1] = true;
    priority_queue<P> q;
    for(auto &p : v[1]){
        q.push(P(-p.second, p.first));
    }
    
    int ans = 0;
    
    while(!q.empty()){
        auto p = q.top();
        q.pop();
        
        if(!visited[p.second]){
            visited[p.second] = true;
            ans += -p.first;
            
            for(auto &a : v[p.second]){
                q.push(P(-a.second, a.first));
            }
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
