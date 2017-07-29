//
//  p_2.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 6. 17..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> nums) {
    int pos[250005][2];//x,y 위치 저장
    int answer = 0;
    
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            pos[board[i][j]][0] = i;//1~N 자연수
            pos[board[i][j]][1] = j;
        }
    }
    
    for(int k=0; k<nums.size(); k++){
        //printf("%d: %d,%d \n",nums[k], pos[nums[k]][0], pos[nums[k]][1]);
        board[pos[nums[k]][0]][pos[nums[k]][1]] = 0;
    }
    
    
    int cnt = 0;
    
    for(int i=0; i<board.size(); i++){//가로,세로
        bool row = true;
        bool col = true;
        
        for(int j=0; j<board[i].size(); j++){
            if(row && board[i][j] != 0){
                row = false;
            }
            if(col && board[j][i] != 0){
                col = false;
            }
        }
        if(row)
            cnt += 1;
        if(col)
            cnt += 1;
    }
    
    bool line1 = true; //대각1
    for(int i=0; i<board.size(); i++){
        if(board[i][i] != 0)
            line1 = false;
    }
    
    bool line2 = true; //대각2
    for(int i=board.size()-1; i>=0; i--){
        if(board[board.size()-1-i][i] != 0)
            line2 = false;
    }
    
    if(line1)
        cnt += 1;
    if(line2)
        cnt += 1;
    
    printf("%d\n", cnt);
    
    
    return answer;
}

int main(){
//    vector<vector<int>> v = {{11,13,15,16},{12,1,4,3},{10,2,7,8},{5,14,6,9}};
//    vector<int> vv = {14,3,2,4,13,1,16,11,5,15};
    vector<vector<int>> v = {{6,15,17,14,23},{5,12,16,13,25},{21,4,2,1,22},{10,20,3,18,8},{11,9,19,24,7}};
    vector<int> vv = {15,7,2,25,9,16,12,18,5,4,10,13,20};
    solution(v, vv);
    return 0;
}
