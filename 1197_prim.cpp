//
//  1197_prim.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 12..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> P;

vector<P> v[10002];
bool visited[10002];

int main(){
    int n,e;
    cin >> n >> e;
    
    for(int i=1; i<=e; i++){
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        v[t1].push_back(P(t2,t3));
        v[t2].push_back(P(t1,t3));
    }
    
    priority_queue<P> q;
    visited[1] = true;
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
            
            for(auto &a: v[p.second]){
                q.push(P(-a.second, a.first));
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
