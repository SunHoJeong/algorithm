//
//  14226.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 6..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> P;

queue<P> q;
int dist[1001][1001];
bool visited[1001][1001];
int ans = 1000000000;

int main(){
    //화면:s
    //클립보드:c
    int n;
    cin >> n;
    q.push(P(1,0));
    dist[1][0] = 0;
    
    while(!q.empty()){
        auto a = q.front();
        int s = a.first;
        int c = a.second;
        //cout << s << "," << c << ":" << dist[s][c] << "\n";
        q.pop();
        
        if(s == n){
            if(dist[s][c] < ans ){
                ans = dist[s][c];
            }
        }
        
        if(!visited[s][s]){
            dist[s][s] = dist[s][c]+1;
            visited[s][s] = true;
            q.push(P(s,s));
        }
        if(s+c <= n && !visited[s+c][c]){
            dist[s+c][c] = dist[s][c] + 1;
            visited[s+c][c] = true;
            q.push(P(s+c,c));
        }
        if(2<=s-1 && !visited[s-1][c]){
            dist[s-1][c] = dist[s][c] + 1;
            visited[s-1][c] = true;
            q.push(P(s-1,c));
        }
        
    }
    
    cout << ans << "\n";
    
    return 0;
}
