//
//  5427.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 4..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

int n;
int graph[1001][1001] = {0,};
int w;
int h;
queue<int> q;
queue<int> s_q;

void move(int depth){
    //depth == 상근이가 있던 위치
    
    for(int i=1; i<=h; i++){//불 큐에넣기
        for(int j=1; j<=w; j++){
            if(graph[i][j] == -3){
                q.push(i*10000+j);
                //printf("불push:%d %d, depth:%d\n", i,j,depth);
            }
            else if(graph[i][j] == depth){
                s_q.push(i*10000+j);
                //printf("상근push: %d %d depth:%d\n", i,j,depth);
            }
        }
    }
    
    while(!q.empty()){ //fire pop
        int start = q.front();
        q.pop();
        int f_row = start/10000;
        int f_col = start%10000;
        
        if(graph[f_row][f_col+1] >= -1){ //빈공간, 상근이가 지나간곳
            graph[f_row][f_col+1] = -3;
        }
        if(graph[f_row+1][f_col] >= -1){
            graph[f_row+1][f_col] = -3;
        }
        if(graph[f_row][f_col-1] >= -1){
            graph[f_row][f_col-1] = -3;
        }
        if(graph[f_row-1][f_col] >= -1){
            graph[f_row-1][f_col] = -3;
        }
    }

    bool flag = false;

    while(!s_q.empty()){ //상근 pop
//        if(s_q.front() != depth)
//            continue;
        int start = s_q.front();
        s_q.pop();
        int s_row = start/10000;
        int s_col = start%10000;
        //printf("상근이시작start: %d %d\n", s_row, s_col);
    
        if(graph[s_row][s_col+1] == -1){
            graph[s_row][s_col+1] = depth +1;
            flag = true;
            //printf("우\n");
            if(s_row == 1 || s_row == h || s_col+1 ==1 || s_col+1 == w){
                printf("%d\n", graph[s_row][s_col+1]+1);
                return;
            }
        }
        if(graph[s_row+1][s_col] == -1){
            graph[s_row+1][s_col] = depth +1;
            flag = true;
            //printf("하\n");
            if(s_row +1 ==1 ||s_row + 1 == h || s_col ==1 || s_col == w){
                printf("%d\n", graph[s_row+1][s_col]+1);
                return;
            }
        }
        if(graph[s_row][s_col-1] == -1){
            graph[s_row][s_col-1] = depth +1;
            flag = true;
            //printf("좌\n");
            if(s_row ==1 || s_row == h || s_col -1 ==1 || s_col -1 == w){
                printf("%d\n", graph[s_row][s_col-1]+1);
                return;
            }
        }
        if(graph[s_row-1][s_col] == -1){
            graph[s_row-1][s_col] = depth +1;
            flag = true;
            //printf("상\n");
            if(s_row -1 ==1 ||s_row -1 == h || s_col == 1 || s_col == w){
                printf("%d\n", graph[s_row-1][s_col]+1);
                return;
            }
        }
        
        
        /*printf("--depth:%d--\n",depth);
        for(int i=0; i<=h+1; i++){
            
            for(int j=0; j<=w+1; j++){
                printf("%3d", graph[i][j]);
            }
            printf("\n");
        }*/
        
    }
    
    if(!flag){
        printf("IMPOSSIBLE\n");
        return;
    }
    move(depth+1);
    
    
}

int main(){
    scanf("%d", &n);
    
    while(n--){
        
        scanf("%d %d", &w, &h);
        
        for(int i=0; i<=h+1; i++){
            for(int j=0; j<=w+1; j++){
                graph[i][j] = -2;
            }
        }
        bool flag = false;
        
        for(int i=1; i<=h; i++){
            char input[1001];
            scanf("%s", input);
            for(int j=0; j<w; j++){
                if(input[j] == '.'){//-1 빈공간
                    graph[i][j+1] = -1;
                }
                else if(input[j] == '#'){//-2 벽
                    graph[i][j+1] = -2;
                }
                else if(input[j] == '@'){//0 상근이의 시작위치
                    if(i == 1 || i == h || j+1 ==1 || j+1 == w){
                        flag = true;
                    }
                    graph[i][j+1] = 0;
                }
                else if(input[j] == '*'){//-3 불
                    graph[i][j+1] = -3;
                }
            }
        }
        
        /*for(int i=0; i<=h+1; i++){
            for(int j=0; j<=w+1; j++){
                printf("%3d", graph[i][j]);
            }
            printf("\n");
        }
        printf("\n");*/
        if(flag){
            printf("%d\n",1); //시작위치가 모서리에 위치
        }
        else{
            move(0);
        }
    
    }
    
}
