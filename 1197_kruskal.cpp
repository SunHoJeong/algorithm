//
//  1197_kruskal.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 12..
//  Copyright © 2017년 수노. All rights reserved.
//

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
    if(x == p[x]){
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
        p[i] = i;
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
        if(Find(e.st) != Find(e.end) ){
            Union(e.st, e.end);
            ans += e.cost;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
