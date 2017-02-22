//
//  2665_dijkstra.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 21..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> P;
const int INF = 1000000000;

int graph[55][55];
int dist[55][55];
bool visited[55][55];
int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1} };
priority_queue<P, vector<P>, greater<P> > q;

int main(){
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        string str;
        cin >> str;
        for(int j=0; j<n; j++){
            if(str[j] == '0'){
                graph[i][j+1] = 1;
            }
            else{
                graph[i][j+1] = 0;
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dist[i][j] = INF;
        }
    }
    dist[1][1] = graph[1][1];
    q.push(P(dist[1][1], 10001));
    //cout << visited[1][1] << "\n";
    for(int k=1; k<=n*n-1; k++){
        int r, c;
        do{
            r = q.top().second/10000;
            c = q.top().second%10000;
            //cout << r << "," << c << "\n";
            q.pop();
            
        }while(visited[r][c]);
        
        visited[r][c] = true;
        
        for(int i=0; i<4; i++){
            int rr = r+dir[i][0];
            int cc = c+dir[i][1];
            
            if(rr <= 0 || rr > n || cc <= 0 || cc > n)
                continue;
            
            if(dist[rr][cc] > dist[r][c] + graph[rr][cc]){
                dist[rr][cc] = dist[r][c] + graph[rr][cc];
                q.push(P(dist[rr][cc], rr*10000+cc));
            }
        }
        
    }
    
    cout << dist[n][n] << "\n";
           
    
    return 0;
}
