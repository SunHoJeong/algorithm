//
//  p_3.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 6. 17..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> P;

int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
queue<P> bomb_q;
queue<P> a_q;
queue<P> b_q;

int solution(vector<vector<int> > board, int K, int Ax, int Ay, int Bx, int By) {
    //k=폭발범위,A와B의 좌표
    int answer = 0;
    int graphA[16][16];
    int graphB[16][16];
    
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j] == 1){
                bomb_q.push(P(i,j));
            }
        }
    }
    
    a_q.push(P(Ax,Ay));
    b_q.push(P(Bx,By));
    
    while(!bomb_q.empty()){
        int row = bomb_q.front().first;
        int col = bomb_q.front().second;
        bomb_q.pop();
        
        for(int i=0; i<4; i++){
            int rr = row;
            int cc = col;
            for(int j=0; j<K; j++){
                rr += dir[i][0];
                cc += dir[i][1];
                
                if(0<=rr && rr<board.size() && 0<=cc && cc<board.size()){
                    if(board[rr][cc] == 2 || board[rr][cc] == 1)
                        break;
                    board[rr][cc] = 3;//폭발구간
                }
                    
            }
        }
    }
    
    int n = (int)board.size();
    for(int a=0; a<n*n; a++){
        int sizeA = (int)a_q.size();
        for(int b=0; b<sizeA; b++){
            int row = a_q.front().first;
            int col = a_q.front().second;
            a_q.pop();
            
            for(int i=0; i<4; i++){
                int rr = row+dir[i][0];
                int cc = col+dir[i][1];
                if(0<=rr && rr<board.size() && 0<=cc && cc<board.size()){
                    if(board[rr][cc] != 1 && board[rr][cc] != 2){
                        //빈칸 or 폭발지역
                        graphA[rr][cc] = a+1;
                        a_q.push(P(rr,cc));
                    }
                }
            }
        }
        
        int sizeB = (int)b_q.size();
        for(int c=0; c<sizeB; c++){
            int row = b_q.front().first;
            int col = b_q.front().second;
            b_q.pop();
            
            for(int i=0; i<4; i++){
                int rr = row+dir[i][0];
                int cc = col+dir[i][1];
                if(0<=rr && rr<board.size() && 0<=cc && cc<board.size()){
                    if(board[rr][cc] != 1 && board[rr][cc] != 2 && graphA[rr][cc] != a){
                        //빈칸 or 폭발지역
                        graphB[rr][cc] = a+1;
                        b_q.push(P(rr,cc));
                    }
                }

            }
        }
        
        int save=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(graphA[i][j] == a+1 && board[i][j] == 0){
                    save = i*10000+j;
                    for(int k=0; k<n; k++){
                        for(int l=0; l<n; l++){
                            if(graphB[k][l] == a+1 && board[k][l] == 0){
                                return a+1;
                            }
                            
                        }
                    }
                }
            }
        }

        
        
    }
    
    return answer;
}

int main(){
    vector<vector<int> > v = {{1,2,0,0},{1,0,2,0},{1,0,0,0},{1,0,0,1}};
    int num = solution(v, 2, 1, 1, 2, 2);
    cout << num << "\n";
    return 0;
}
