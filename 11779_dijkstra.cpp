//
//  11779.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 14..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef pair<int, int> P;
const int INF = 1000000000;

vector<P> v[1005];
bool visited[1005];
int dist[1005];
int root[1005];

int main(){
    int n,m;
    cin >> n;
    cin >> m;
    for(int i=0; i<m; i++){
        int t1,t2,t3;
        cin >> t1 >> t2 >> t3;
        v[t1].push_back(P(t2,t3));
    }
    
    int st, des;
    cin >> st >> des;
    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }
    dist[st] = 0;
    root[st] = -1;
    
    for(int k=0; k<n-1; k++){
        int min = INF;
        int index = 0;
        
        for(int i=1; i<=n; i++){
            if(!visited[i] && min > dist[i]){
                min = dist[i];
                index = i;
            }
        }
        visited[index] = true;
        
        for(auto &p : v[index]){
            if(dist[p.first] > dist[index] + p.second){
                dist[p.first] = dist[index] + p.second;
                root[p.first] = index;
            }
        }
    }
    cout << dist[des] << "\n";
    stack<int> s;
    int x = des;
    while(x != st){
        s.push(x);
        x = root[x];
    }
    s.push(st);
    cout << s.size() <<"\n";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
    
    
    return 0;
}
