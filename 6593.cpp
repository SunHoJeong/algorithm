//
//  6593.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 22..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
const int INF = 1000000000;
typedef pair<int, int> P;

int dir[6][3] = {{1,0,0}, {-1,0,0}, {0,0,1}, {0,0,-1}, {0,-1,0}, {0,1,0} };

int main(){
    int l,r,c;
    int st = 0, end=0;
    
    while(true){
        scanf("%d %d %d", &l, &r ,&c);
        if(l==0 && r==0 && c==0)
            break;
        
        int graph[l+1][r+1][c+1];
        int dist[l+1][r+1][c+1];
        bool visited[l+1][r+1][c+1];
       
        priority_queue<P, vector<P>, greater<P> > q;
        memset(graph, 0, sizeof(graph));
        memset(dist, 0, sizeof(dist));
        memset(visited, false , sizeof(visited));
        bool check = false;
        
        for(int k=1; k<=l; k++){
            for(int i=1; i<=r; i++){
                char str[c+1];
                scanf("%s", str);
                for(int j=0; j<c; j++){
                    if(str[j] == '.'){
                        graph[k][i][j+1] = 1;
                    }
                    else if(str[j] == '#'){
                        graph[k][i][j+1] = 0;
                    }
                    else if(str[j] == 'S'){
                        graph[k][i][j+1] = 1;
                        st = k*10000 + i*100 + j+1;
                    }
                    else if(str[j] == 'E'){
                        graph[k][i][j+1] = 1;
                        end = k*10000 + i*100 + j+1;
                    }
                    
                }
            }
        }
        
        for(int i=1; i<=l; i++){
            for(int j=1; j<=r; j++){
                for(int k=1; k<=c; k++){
                    dist[i][j][k] = INF;
                }
            }
        }
        
        int st_l = st/10000;
        int st_r = (st/100)%100;
        int st_c = st%100;
        int end_l = end/10000;
        int end_r = (end/100)%100;
        int end_c = end%100;
        dist[st_l][st_r][st_c] = 0;
        q.push(P(dist[st_l][st_r][st_c], st));
        
        bool flag = false;
        while(!q.empty()){
            int t_l, t_r, t_c;
            do{
                t_l = q.top().second/10000;
                t_r = (q.top().second/100)%100;
                t_c = q.top().second%100;
                //printf("%d %d %d\n",t_l,t_r,t_c);
                q.pop();
                if(t_l == end_l && t_r == end_r && t_c == end_c){
                    flag = true;
                }
                
            }while(visited[t_l][t_r][t_c]);
            
            if(flag){
                check = true;
                break;
            }

            visited[t_l][t_r][t_c] = true;
            
            for(int i=0; i<6; i++){
                int ll = t_l + dir[i][0];
                int rr = t_r + dir[i][1];
                int cc = t_c + dir[i][2];
                //printf("ll,rr,cc %d %d %d\n",ll,rr,cc);
                
                if(ll <= 0 || ll > l || rr <= 0 || rr > r || cc <= 0 || cc > c)
                    continue;
                
                if(graph[ll][rr][cc] == 1 && dist[ll][rr][cc] > dist[t_l][t_r][t_c] +1){
                    dist[ll][rr][cc] = dist[t_l][t_r][t_c] +1;
                    //printf("%d %d\n",dist[ll][rr][cc], ll*10000+rr*100+cc);
                    q.push(P(dist[ll][rr][cc], ll*10000+rr*100+cc));
                    
                }
                
            }
            
        }
        
        while(!q.empty()){
            q.pop();
        }
        if(!check){
            printf("Trapped!\n");
        }
        else{
            printf("Escaped in %d minute(s).\n",dist[end_l][end_r][end_c]);

        }
    
    }
    
    
    return 0;
}
