//
//  9376.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 26..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;
const int INF = 1000000000;
typedef pair<int, int> P;

int graph[102][102];
bool visited[102][102];
int dist[102][102];
int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
queue<P> s_q;
queue<P> q;

int main(){
    
    int t;
    scanf("%d", &t);
    while(t--){
        
        int row, col;
        scanf("%d %d", &row, &col);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                dist[i][j] = INF;
                graph[i][j] = 0;
                visited[i][j] = false;
            }
        }
        
        for(int i=0; i<row; i++){//*==-1, #==-2, .==-3 $==0
            char input[col];
            scanf("%s", input);
            for(int j=0; j<col; j++){
                if(input[j] == '*'){
                    graph[i][j] = -1;
                }
                else if(input[j] == '#'){
                    graph[i][j] = -2;
                }
                else if(input[j] == '.'){
                    graph[i][j] = -3;
                }
                else{ //$
                    graph[i][j] = 0;
                    s_q.push(P(i,j));
                }
            }
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                printf("%d ", graph[i][j]);
            }
            printf("\n");
        }
        
        while(!s_q.empty()){ // 죄수 담은 큐
            int ans = INF+1;
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    dist[i][j] = INF;
                    visited[i][j] = false;
                }
            }
            int st_r = s_q.front().first;
            int st_c = s_q.front().second;
            s_q.pop();
            printf("start:%d %d\n", st_r, st_c);

            dist[st_r][st_c] = 0; //시작지점 설정
            
            for(int k=0; k<row*col-1; k++){
                int min = INF+1;
                int min_r = -3;
                int min_c = -3;
                for(int i=0; i<row; i++){
                    for(int j=0; j<col; j++){
                        //printf("min:%d dist:%d i:%d j:%d\n",min, dist[i][j], i, j);
                        if(!visited[i][j] && min > dist[i][j]){
                            min = dist[i][j];
                            min_r = i;
                            min_c = j;
                        }
                    }
                }
                printf("m_r:%d, m_c:%d , %d\n", min_r, min_c,graph[min_r][min_c]);
                visited[min_r][min_c] = true;
                
                for(int a=0; a<4; a++){
                    int rr = min_r + dir[a][0];
                    int cc = min_c + dir[a][1];
                    //printf("rr:%d cc:%d\n", rr,cc);
                    
                    if(0>rr || rr >=row || 0 > cc || cc >= col)
                        continue;
                    
                    
                    if(graph[rr][cc] != -1){
                        if(graph[rr][cc] == -2 && dist[rr][cc] > dist[min_r][min_c]+1){//#
                            dist[rr][cc] = dist[min_r][min_c] + 1;
                            graph[rr][cc] = -3; // '.'
                            if(rr==0 || cc==0 || rr==row-1 || cc==col-1){
                                if(ans > dist[rr][cc]){
                                    ans = dist[rr][cc];
                                    printf("result:%d\n",dist[rr][cc]);

                                }

                            }
                            
                        }
                        else if(graph[rr][cc] == -3){//.
                            dist[rr][cc] = dist[min_r][min_c];
                            if(rr==0 || cc==0 || rr==row-1 || cc==col-1){
                                if(ans > dist[rr][cc]){
                                    ans = dist[rr][cc];
                                    printf("result:%d\n",dist[rr][cc]);
                                }

                            }
                        }
                    }
                }
                
            }
            
        }
        
        
    }
    return 0;
}
