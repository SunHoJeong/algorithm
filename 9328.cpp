//
//  9328.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 11..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
typedef pair<int,int> P;

queue<P> q;
queue<P> wait_q[26];

int row, col;
char graph[102][102];
bool visited[102][102];
bool key[26];
int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1}};
int ans = 0;
bool flag = false;

void bfs(){
    while(!q.empty()){
        auto a = q.front();
        int r = a.first;
        int c = a.second;
        q.pop();

        for(int i=0; i<4; i++){
            int rr = r + dir[i][0];
            int cc = c + dir[i][1];
            
            if(r < 0  || r >= row || c < 0 || c >= col)
                continue;
            
            if(!visited[rr][cc]){
                if(graph[rr][cc] == '.'){//빈공간
                    visited[rr][cc] = true;
                    q.push(P(rr,cc));
                }
                else if(0 <= graph[rr][cc]-'A' && graph[rr][cc]-'A' <= 26){//대문자==문
                    visited[rr][cc] = true;
                    wait_q[graph[rr][cc]-'A'].push(P(rr,cc));
                }
                else if(0 <= graph[rr][cc]-'a' && graph[rr][cc]-'a' <= 26){//소문자==열쇠
                    visited[rr][cc] = true;
                    key[graph[rr][cc]-'a'] = true;
                    graph[rr][cc] = '.';
                    q.push(P(rr,cc));
                }
                else if(graph[rr][cc] == '$'){//서류
                    visited[rr][cc] = true;
                    ans += 1;
                    q.push(P(rr,cc));
                }
            }
        }
    }
}

void waitToq(){
    for(int i=0; i<26; i++){
        if(key[i]){
            while(!wait_q[i].empty()){
                auto a = wait_q[i].front();
                wait_q[i].pop();
                flag = true;
                graph[a.first][a.second] = '.';
                
                q.push(P(a.first,a.second));
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> row >> col;
        
        while(!q.empty()){
            q.pop();
        }
        for(int i=0; i<26; i++){
            while(!wait_q[i].empty())
                wait_q[i].pop();
        }
        
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
        memset(key, 0, sizeof(key));
        ans = 0;//init ans
        
        for(int i=0; i<row; i++){
            cin >> graph[i];
        }
       
        char k[26]; //input key
        cin >> k;
        int len = (int)strlen(k);
        for(int i=0; i<len; i++){
            if(k[i] == '0')
                break;
            key[k[i]-'a'] = true;
        }
        
        for(int i=0; i<row; i++){ //모서리 탐색 '.' , 대문자
            if(i==0 || i==row-1){
                for(int j=0; j<col; j++){
                    if(graph[i][j] == '.'){
                        visited[i][j] = true;
                        q.push(P(i,j));
                    }
                    else if(0<= graph[i][j]-'A' && graph[i][j]-'A' <=26){
                        visited[i][j] = true;
                        wait_q[graph[i][j]-'A'].push(P(i,j));
                    }
                    else if(0<= graph[i][j]-'a' && graph[i][j]-'a' <=26){
                        visited[i][j] = true;
                        key[graph[i][j]-'a'] = true;
                        graph[i][j] = '.';
                        q.push(P(i,j));
                    }
                    else if(graph[i][j] == '$'){
                        visited[i][j] = true;
                        ans += 1;
                        q.push(P(i,j));
                    }
                }
            }
            else{//graph[i][0] , graph[i][col-1]
                if(graph[i][0] == '.'){
                    visited[i][0] = true;
                    q.push(P(i,0));
                }
                else if(0<= graph[i][0]-'A' && graph[i][0]-'A' <=26){
                    visited[i][0] = true;
                    wait_q[graph[i][0]-'A'].push(P(i,0));
                }
                else if(0<= graph[i][0]-'a' && graph[i][0]-'a' <=26){
                    visited[i][0] = true;
                    key[graph[i][0]-'a'] = true;
                    graph[i][0] = '.';
                    q.push(P(i,0));
                }
                else if(graph[i][0] == '$'){
                    visited[i][0] = true;
                    ans += 1;
                    q.push(P(i,0));
                }
                
                if(graph[i][col-1] == '.'){
                    visited[i][col-1] = true;
                    q.push(P(i,col-1));
                }
                else if(0<= graph[i][col-1]-'A' && graph[i][col-1]-'A' <=26){
                    visited[i][col-1] = true;
                    wait_q[graph[i][col-1]-'A'].push(P(i,col-1));
                }
                else if(0<= graph[i][col-1]-'a' && graph[i][col-1]-'a' <=26){
                    visited[i][col-1] = true;
                    key[graph[i][col-1]-'a'] = true;
                    graph[i][col-1] = '.';
                    q.push(P(i,col-1));
                }
                else if(graph[i][col-1] == '$'){
                    visited[i][col-1] = true;
                    ans += 1;
                    q.push(P(i,col-1));
                }
            }
        }
        
        while(1){
            bfs();
            waitToq();
            if(q.empty()){
                break;
            }
            flag = false;
        }
        cout << ans << "\n";
        
        
    }//while
    return 0;
}
