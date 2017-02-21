//
//  prim_algorithm.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 20..
//  Copyright © 2017년 수노. All rights reserved.
//

//prim-algorithm
//MST(Minimum Spanning Tree)를 만드는 알고리즘
//랜덤으로 노드 선택 -> 선택된 노드로부터 다른 노드까지의 경로를 큐에 추가 ->
//cost가 가장 작은 경로 선택 -> 선택된 경로로 이어지는 노드 반복

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> P;

vector<P> v[10001];
bool visited[10001];

int main(){
    int n,e; //node 수
    cin >> n >> e;
    
    for(int i=1; i<=e; i++){
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        v[t1].push_back(P(t2, t3)); //방향성이 없는 그래프
        v[t2].push_back(P(t1, t3));
    }
    priority_queue<P> q;
    
    visited[1] = true;
    for(auto &p : v[1]){// st:1
        q.push(P(-p.second, p.first)); // -cost , des
    }
    
    int ans = 0; //cost
    
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
    return 0;
}
