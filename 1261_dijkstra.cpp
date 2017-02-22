//
//  1261_dijkstra.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 20..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> P;
const int INF = 1000000000;

priority_queue<P, vector<P>, greater<P>> q;
int graph[105][105];
int dist[105][105];
bool visited[105][105];
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

int main(){
    int row, col;
    cin >> col >> row;
    
    for(int i=1; i<=row; i++){
        string str;
        cin >> str;
        for(int j=0; j<col; j++){
            if(str[j] == '0'){
                graph[i][j+1] = 0;
            }
            else if(str[j] == '1'){
                graph[i][j+1] = 1;
            }
        }
    }
    
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            dist[i][j] = INF;
        }
    }
    
    dist[1][1] = 0;
    q.push(P(0,10001));
    
    for(int k=1; k<=row*col-1; k++){
        int r,c;
        do{
            auto temp = q.top();
            r = temp.second/10000;
            c = temp.second%10000;
            q.pop();
            //cout << k << ":" << r<<","<<c<<"\n";
        }while(visited[r][c]);
        
        visited[r][c] = true;
        
        for(int i=0; i<4; i++){
            int rr = r+dir[i][0];
            int cc = c+dir[i][1];
            
            if(rr <= 0 || row < rr || cc <= 0 || col < cc)
                continue;
            
            if(dist[r][c] + graph[rr][cc] < dist[rr][cc]){
                dist[rr][cc] = dist[r][c] + graph[rr][cc];
                q.push(P(dist[rr][cc], rr*10000+cc));
            }
        }
    }
    
    cout << dist[row][col] << "\n";
    
    return 0;
}
