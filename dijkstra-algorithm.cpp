//
//  dijkstra-algorithm.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 20..
//  Copyright © 2017년 수노. All rights reserved.
//

//dijkstra-algorithm
//최단경로를 찾는 알고리즘
//check 되어있지않은 가장 작은 dist[i]를 선택
//i와 연결된 모든 경로를 업데이트
//모든 노드가 check되면 종료

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1000000000;
typedef pair<int, int> P;

vector<P> v[10005];
int dist[10005];
bool visited[10005];

int main(){
    int n,m;
    cin >> n;
    cin >> m;
    
    for(int i=0; i<m; i++){
        int t1, t2, t3;
        cin >> t1 >> t2>> t3;
        v[t1].push_back(P(t2, t3));
    }
    int st, des;
    cin >> st >> des;
    
    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }
    
    dist[st] = 0;
    
    for(int k=0; k<n-1; k++){
        int min = INF+1;
        int index = 0;
        
        for(int i=1; i<=n; i++){
            if(!visited[i] && min > dist[i]){
                min = dist[i];
                index = i;
            }
        }
        
        visited[index] = true;
        
        for(auto &p: v[index]){ // index -> p.first : p.second
            if(dist[p.first] > dist[index] + p.second ){ //최소거리 업데이트
                dist[p.first] = dist[index] + p.second;
            }
        }
        
    }
    for(int i=1; i<=n; i++){
        cout << dist[i] << "\n";
    }
    
    return 0;
}
