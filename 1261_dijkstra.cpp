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
    q.push(P(0,1));
    
    for(int k=1; k<=row*col; k++){
        
    }
    
    return 0;
}
