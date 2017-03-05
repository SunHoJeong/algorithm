//
//  1941.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 5..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>

using namespace std;

char graph[6][6];
bool visited[6][6];
bool start[6][6];

int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
int ans=0;

void back(int r, int c, int s_num, int depth){
    printf("%d,%d num:%d dep:%d\n",r,c,s_num,depth);
    if(depth == 7){
        if(s_num >= 4){
            ans++;
        }
    }
    
    if(depth >= 4 && depth-s_num > 3){
        return;
    }
    
    for(int i=0; i<4; i++){
        int rr = r+dir[i][0];
        int cc = c+dir[i][1];
        if(rr < 0 || rr >=5 || cc < 0 || cc>=5)
            continue;
        if(!start[rr][cc]){
            visited[rr][cc] = true;
            if(graph[rr][cc] == 'Y'){
                back(rr, cc, s_num, depth+1);
            }
            else{
                back(rr, cc, s_num+1, depth+1);
            }
            visited[rr][cc] = false;
        }
    }
}

int main(){
    for(int i=0; i<5; i++){
        scanf("%s", graph[i]);
    }
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            printf("%c ",graph[i][j]);
        }
        printf("\n");
    }
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(!visited[i][j] && !start[i][j]){
                visited[i][j] = true;
                start[i][j] = true;
                if(graph[i][j] == 'Y'){
                    back(i,j,0,1);
                }
                else{
                    back(i,j,1,1);
                }
                visited[i][j] = false;
            }
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
