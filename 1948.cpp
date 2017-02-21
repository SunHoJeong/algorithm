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
vector<P> rev[10005];
bool visited[10005][10005];
queue<int> q;
int ind[10005];
int dist[10005];

int main(){
    int n,m;
    cin >> n;
    cin >> m;
    for(int i=0; i<m; i++){
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        ind[t2] += 1;
        v[t1].push_back(P(t2, t3));
        rev[t2].push_back(P(t1, t3));
    }
    
    int st, des;
    cin >> st >> des;
    
    for(int i=1; i<=n; i++ ){
        //cout << i << "," << ind[i] << "\n";
        if(ind[i] == 0){
            q.push(i);
        }
    }
    
    for(int i=1; i<=n; i++){
        int x = q.front();
        q.pop();
        
        for(auto &p : v[x]){
            int node = p.first;
            int cost = p.second;
            ind[node] -= 1;
            if(dist[node] <= dist[x] + cost){
                dist[node] = dist[x] + cost;
                //cout << "1부터" << node <<"까지:"<<dist[node] << "\n";
                //cout << "from" << x << "to" << node << "\n";
            }
            if(ind[node] == 0){
                q.push(node);
            }
        }
    }

    while(!q.empty()){
        q.pop();
    }
    
    q.push(des);
    int ans = 0;
    while(!q.empty()){
        int st = q.front();
        q.pop();
        
        for(auto &p: rev[st]){
            if(dist[st] == dist[p.first] + p.second && !visited[st][p.first]){
                //cout <<st << "->"<< p.first << ":" << p.second << "\n";
                visited[st][p.first] = true;
                q.push(p.first);
                ans ++;
            }
        }
    }
    cout << dist[des] << "\n";
    cout << ans << "\n";
    
    

    return 0;
}
