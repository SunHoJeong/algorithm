//
//  1389.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 24..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
const int INF = 1000000000;

vector<int> v[101];
int d[101];
bool visited[101];
int dist[101][101];

void dfs(int x, int st, int des, int depth){
    visited[x] = true;
    
    if(x==des){
        if(dist[st][des] > depth){
            dist[st][des] = depth;
            cout << st << "->" << x <<":"<<depth<<"\n";
        }
        return;
    }
    
    for(int a : v[x] ){// x->a
        if(!visited[a]){
            dfs(a, st, des, depth + 1);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dist[i][j] = INF;
        }
    }
    
    for(int i=1; i<=n; i++){
        cout << i << ": " ;
        for(int con : v[i]){
            cout << con << " ";
        }
        cout << "\n";
    }
    
    for(int i=1; i<=n; i++){// i -> j
        for(int j=1; j<=n; j++){
            if(i != j){
                memset(visited, false, sizeof(visited));
                dfs(i, i, j, 0);
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j] != INF)
                d[i] += dist[i][j];
        }
    }
    
    for(int i=1; i<=n; i++){
        cout << d[i] << " ";
    }
    
    
    
    return 0;
}
