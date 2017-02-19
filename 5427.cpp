//
//  5427.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 4..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <string>
#include <queue>

using namespace std;

int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int col, row;
int graph[1003][1003];


void sol(queue<int> sg_q, queue<int> fire_q){
    bool flag = true;
    
    while(flag){
//        for(int i=1; i<=row; i++){
//            for(int j=1; j<=col; j++){
//                cout << graph[i][j] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";
        int sg_len = sg_q.size();
        for(int i=0; i<sg_len; i++){
            int s_start = sg_q.front();
            sg_q.pop();
            int s_row = s_start/10000;
            int s_col = s_start%10000;
//            if(s_row == 1 || s_row == row || s_col == 1 || s_col == col){
//                if(graph[s_row][s_col] == -3){
//                    cout << "1\n";
//                    return;
//                }
//            }
            
            for(int i=0; i<4; i++){
                int sr = s_row+dir[i][0];
                int sc = s_col+dir[i][1];
                
                if(0 < sr && sr <= row && 0 < sc && sc <= col &&
                   graph[sr][sc] == 0){
                    if(graph[s_row][s_col] == -3){
                        graph[sr][sc] =1;
                    }
                    else{
                        graph[sr][sc] = graph[s_row][s_col]+1;
                    }
                    
                    if(sr == 1 || sr == row || sc == 1 || sc == col){
                        //cout << sr << "," << sc << "\n";
                        cout << graph[sr][sc]+1<<"\n";
                        return;
                    }
                    sg_q.push(sr*10000+sc);
                }
            }
        }
        
        if(sg_q.size() == 0){
            cout << "IMPOSSIBLE\n";
            
            return;
        }
        
        int f_len = fire_q.size();
        for(int i=0; i<f_len; i++){
            int f_start = fire_q.front();
            fire_q.pop();
            int f_row = f_start/10000;
            int f_col = f_start%10000;
            
            for(int i=0; i<4; i++){
                int fr = f_row+dir[i][0];
                int fc = f_col+dir[i][1];
                
                if(0 < fr && fr <= row && 0 < fc && fc <= col &&
                   graph[fr][fc] != -1 && graph[fr][fc] != -2){
                    graph[fr][fc] = -2;
                    fire_q.push(fr*10000+fc);
                }
            }
        }
        
        
    }
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        memset(graph, -1, sizeof(graph));
        queue<int> fire_q;
        queue<int> sg_q;
        cin >> col >> row;
        
        bool check = false;
        for(int i=1; i<=row; i++){
            string str;
            cin >> str;
            for(int j=0; j<col; j++){
                if(str[j] == '#'){ //벽
                    graph[i][j+1] = -1;
                }
                else if(str[j] == '.'){ //빈공간
                    graph[i][j+1] = 0;
                }
                else if(str[j] == '@'){ //상근 시작위치
                    if(i==1 || i==row || j+1 ==1 || j+1 == col){
                        check = true;
                    }
                    graph[i][j+1] = -3;
                    sg_q.push(i*10000+j+1);
                }
                else{ // 불
                    graph[i][j+1] = -2;
                    fire_q.push(i*10000+j+1);
                }
            }
        }
        if(check){
            cout << "1\n" ;
        }
        else{
            sol(sg_q, fire_q);
        }
        
    }
    return 0;
}
