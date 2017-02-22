//
//  1848.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 21..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1000000000;
typedef pair<int, int> P;

vector<P> v[5005];
vector<P> rev[5005];
int dist[5005][5005];
int rev_dist[5005][500];
bool visited[5005][5005];
priority_queue<P, vector<P>, greater<P> > q;

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=4; j++){
            int t1, t2, t3, t4;
            cin >> t1 >> t2 >> t3 >> t4;
            v[t1].push_back(P(t2, t3));
            v[t2].push_back(P(t1, t4));
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dist[i][j] = INF;
            rev_dist[i][j] = INF;
        }
    }
    dist[1][1] = 0;
    q.push(P(dist[1][1], 10001));
    
    for(int i=1; i<=v[1].size(); i++){
        if(!visited[1][)
    }
    
    return 0;
}
