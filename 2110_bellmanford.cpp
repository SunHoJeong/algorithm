//
//  2110.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 13..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;

const int INF = 123456789;

vector<P> v[501];
int graph[502][502];
int dist[502];
int n,c;

int main(){
    for(int i=1; i<=500; i++){
        dist[i] = INF;
    }
    
    cin >> n >> c;
    
    for(int i=0; i<c; i++){
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        v[t1].push_back(P(t2, t3));
    }
    
    dist[1] = 0;
    bool flag = false;
    for(int k=0; k<n; k++){
        for(int i=1; i<=n; i++){ //start node
            for(auto &p : v[i]){
                if(dist[i] != INF && dist[p.first] > dist[i] + p.second){
                    dist[p.first] = dist[i] + p.second;
                    if(k == n-1){
                        flag = true;
                    }
                }
            }
        }
    }
    if(flag){
        cout << -1 << "\n";
    }
    else{
        for(int i=2; i<=n; i++){
            if(dist[i] == INF){
                cout << -1 << "\n";
            }
            else{
                cout << dist[i] << "\n";
            }
        }
    }
    
    return 0;
}
