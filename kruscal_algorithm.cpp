//
//  kruscal_algorithm.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 20..
//  Copyright © 2017년 수노. All rights reserved.
//

//kruskal-algorithm
//MST를 만드는 알고리즘
//모든 경로중에 cost가 가장 적은 경로를 선택
//u->v : c 인 경우에 u노드와 v노드가 같은 집합에 속하지않으면
//경로를 추가

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    int st, end, cost;
    bool operator < (const Edge &other) const{
        return cost < other.cost;
    }
};

int p[10001];

int Find(int x){
    if(p[x] == x){
        return x;
    }
    else{
        return p[x] = Find(p[x]);
    }
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    
    p[b] = a;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<Edge> v(m);
    for(int i=1; i<=n; i++){
        p[i] = 1;
    }
    
    for(int i=0; i<m; i++){
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        v[i].st = t1;
        v[i].end = t2;
        v[i].cost = t3;
    }
    
    sort(v.begin(), v.end());
    
    int ans = 0;
    for(int i=0; i<m; i++){
        Edge e = v[i];
        if(Find(e.st) != Find(e.end)){
            ans += e.cost;
            Union(e.st, e.end);
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
