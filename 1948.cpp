//
//  1948.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 15..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> P;

vector<P> v[10005];
bool visited[10005];
queue<int> q;

int main(){
    int n,m;
    cin >> n;
    cin >> m;
    for(int i=0; i<m; i++){
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        v[t1].push_back(P(t2, t3));
    }
    
    int st, des;
    cin >> st >> des;
    
    visited[st] = true;
    q.push(st);
    
    return 0;
}
