//
//  4485.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 21..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
typedef pair<int, int> P;
const int INF = 1000000000;

int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1} };
int graph[126][126];
bool visited[126][126];
int dist[126][126];

int main(){
    int n;
    int cnt = 0;
    while(true){
        cin >> n;
        if(n==0)
            break;
        cnt += 1;
        
        memset(graph, 0, sizeof(graph));
        memset(visited, false, sizeof(visited));
        priority_queue<P, vector<P>, greater<P> > q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> graph[i][j];
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = INF;
            }
        }
        
        dist[0][0] = graph[0][0];
        q.push(P(dist[0][0],0));
        
        for(int k=0; k<n*n-1; k++){
            int r,c;
            do{
                r = q.top().second/10000;
                c = q.top().second%10000;
                q.pop();
//                cout << k << ":" << r<<","<<c<<"\n";
            }while(visited[r][c]);
            
            visited[r][c] = true;
            
            for(int i=0; i<4; i++){
                int rr = r+ dir[i][0];
                int cc = c+ dir[i][1];
                
                if(rr < 0 || n <=rr || cc < 0 || n <= cc)
                    continue;
                
                if(dist[r][c] + graph[rr][cc] < dist[rr][cc]){
                    dist[rr][cc] = dist[r][c] + graph[rr][cc];
                    q.push(P(dist[rr][cc], rr*10000+cc));
                }
            }
        }
        cout <<"Problem "<<cnt<<": "<< dist[n-1][n-1] << "\n";
    }
}
