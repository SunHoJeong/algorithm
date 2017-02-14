//
//  1753.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 14..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> P;
const int INF = 1000000000;

vector<P> v[20001];
int dist[20001];
bool visited[20001];
priority_queue<P> q;

int main(){
    int n,m;
    cin >> n >> m;
    int st;
    cin >> st;
    for(int i=0; i<m; i++){
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        v[t1].push_back(P(t2, t3));
    }
    
    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }
    dist[st] = 0;
    q.push(P(dist[st], st));
    
    while(!q.empty()){
        auto a = q.top();
        q.pop();
        int node = a.second;
        
        if(visited[node])
            continue;
        
        visited[node] = true;
        
        for(auto &p: v[node]){
            if(dist[p.first] > dist[node] + p.second){
                dist[p.first] = dist[node] + p.second;
                q.push(P(-dist[p.first], p.first));
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(dist[i] == INF){
            cout << "INF\n";
        }
        else{
            cout << dist[i] << "\n";
        }
        
    }
    return 0;
}
