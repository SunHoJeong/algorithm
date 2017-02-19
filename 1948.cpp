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
int ind[10005];

int main(){
    int n,m;
    cin >> n;
    cin >> m;
    for(int i=0; i<m; i++){
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        ind[t2] += 1;
        v[t1].push_back(P(t2, t3));
    }
    
    int st, des;
    cin >> st >> des;
    
    for(int i=1; i<=n; i++ ){
        cout << i << "," << ind[i] << "\n";
        if(ind[i] == 0){
            q.push(i);
        }
    }
    
    visited[st] = true;
    q.push(st);
    
    return 0;
}
