//
//  3055.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 26..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> P;

queue<P> dochi;
queue<P> water;
char graph[51][51];
int val[51][51];
bool dochi_visited[51][51];
bool water_visited[51][51];
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1} };

int main(){
    int row, col;
    int des_row=-1, des_col=-1;
    scanf("%d %d", &row, &col);

    for(int i=0; i<row; i++){
        scanf("%s", graph[i]);
    }
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(graph[i][j] == 'S'){
                dochi_visited[i][j] = true;
                val[i][j] = 0;
                dochi.push(P(i,j));
            }
            else if(graph[i][j] == '*'){
                water_visited[i][i] = true;
                water.push(P(i,j));
            }
            else if(graph[i][j] =='D'){
                des_row = i;
                des_col = j;
            }
        }
    }
    while(!dochi.empty()){
        int wNum = (int)water.size();
        int dNum = (int)dochi.size();
        
        for(int i=0; i<wNum; i++){
            int w_r = water.front().first;
            int w_c = water.front().second;
            water.pop();
            
            for(int k=0; k<4; k++){
                int w_rr = w_r + dir[k][0];
                int w_cc = w_c + dir[k][1];
                
                if(0 > w_rr || w_rr >=row || 0 > w_cc || w_cc >= col)
                    continue;
                //printf("%d %d %c\n",w_rr,w_cc,graph[w_rr][w_cc]);

                if(!water_visited[w_rr][w_cc] && graph[w_rr][w_cc] != 'D'
                   && graph[w_rr][w_cc] != 'X'){
                    water_visited[w_rr][w_cc] = true;
                    graph[w_rr][w_cc] = '*';
                    //val[w_rr][w_cc] = val[w_r][w_c] +1;
                    water.push(P(w_rr,w_cc));
                }
            }
            
        }
        
        for(int j=0; j<dNum; j++){
            int d_r = dochi.front().first;
            int d_c = dochi.front().second;
            dochi.pop();
            
            for(int k=0; k<4; k++){
                int d_rr = d_r + dir[k][0];
                int d_cc = d_c + dir[k][1];
                
                if(0 > d_rr || d_rr >=row || 0 > d_cc || d_cc >=col)
                    continue;
                if(!dochi_visited[d_rr][d_cc] && graph[d_rr][d_cc] != '*'
                   && graph[d_rr][d_cc] != 'X'){
                    dochi_visited[d_rr][d_cc] = true;
                    val[d_rr][d_cc] = val[d_r][d_c] +1;
                    dochi.push(P(d_rr,d_cc));
                    if(d_rr == des_row && d_cc == des_col){
                        printf("%d\n", val[d_rr][d_cc]);
                        return 0;
                    }
                }
            }
            
        }
        
        if(dochi.empty()){
            printf("KAKTUS\n");
            return 0;
        }

    }
    
    return 0;
}
