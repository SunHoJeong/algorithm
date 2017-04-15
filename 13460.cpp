//
//  13460.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 15..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;

struct Pos{
    int cnt, r_row, r_col, b_row, b_col;
};

queue<Pos> q;

char graph[11][11];
int d[11][11][11][11];
int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1}};

int bfs(){
    while(!q.empty()){
        int cnt = q.front().cnt;
        int r_r = q.front().r_row;
        int r_c = q.front().r_col;
        int b_r = q.front().b_row;
        int b_c = q.front().b_col;
        q.pop();
        
        cout << cnt<<":"<<r_r<<","<<r_c<<"  "<<b_r<<","<<b_c<<"\n";
        if(cnt == 11){
            return -1;
        }
        if(graph[r_r][r_c] == 'O' && graph[r_r][r_c] != graph[b_r][b_c])
            return cnt;
        
        for(int i=0; i<4; i++){
            int nr_r = r_r, nr_c = r_c, nb_r = b_r, nb_c = b_c;
            while(graph[nr_r+dir[i][0]][nr_c+dir[i][1]] != '#' &&
                  graph[nr_r][nr_c] != 'O'){
                nr_r += dir[i][0];
                nr_c += dir[i][1];
            }
            
            while(graph[nb_r+dir[i][0]][nb_c+dir[i][1]] != '#' &&
                  graph[nb_r][nb_c] != 'O'){
                nb_r += dir[i][0];
                nb_c += dir[i][1];
            }
            
            if(nr_r == nb_r && nr_c == nb_c){
                if(graph[nr_r][nr_c] == 'O')
                    continue;
                
                //R이 B에 앞섬
                if(abs(r_r-nr_r) + abs(r_c-nr_c) < abs(b_r-nb_r) + abs(b_c-nb_c)){
                    nb_r -= dir[i][0];
                    nb_c -= dir[i][1];
                }
                else{
                    nr_r -= dir[i][0];
                    nr_c -= dir[i][1];
                }
            }
            if(d[nr_r][nr_c][nb_r][nb_c])
                continue;
            d[nr_r][nr_c][nb_r][nb_c] = 1;
            q.push({cnt+1, nr_r, nr_c, nb_r, nb_c});
            
        }
        
    }
    
    return -1;
}

int main(){
    int row, col;
    cin >> row >> col;
    int t1=0, t2=0, t3=0, t4=0;
    
    for(int i=0; i<row; i++){ // 0~row-1 , 0~col-1
        cin >> graph[i];
        for(int j=0; j<col; j++){
            if(graph[i][j] == 'R'){
                t1 = i;
                t2 = j;
            }
            else if(graph[i][j] == 'B'){
                t3 = i;
                t4 = j;
            }
            
        }
    }
    
    d[t1][t2][t3][t4] = 1;
    q.push({0, t1, t2, t3, t4});
    cout << bfs() << "\n";
    
    
    return 0;
}
