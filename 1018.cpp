//
//  1018.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 2..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 1000000000;

int main(){
    int row, col;
    cin >> row >> col;
    char graph[52][52];
    
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            cin >> graph[i][j];
        }
    }
    
    int ans = INF;
    for(int i=1; i<=row-8+1; i++){
        for(int j=1; j<=col-8+1; j++){
            //i,j시작
            int cnt = 0;
            for(int r=1; r<=8; r++){
// sol.1
                for(int c=1; c<=8; c++){
                    if((r+c)%2 == 0 && graph[i+r-1][j+c-1] != 'W'){
                        cnt ++;
                    }
                    else if((r+c)%2 == 1 && graph[i+r-1][j+c-1] != 'B'){
                        cnt ++;
                    }
                }

// sol.2
//                    if(r%2 == 1){//홀수 행
//                        //W시작
//                        if(c%2 == 1 && graph[i+r-1][j+c-1] != 'W'){//홀수 열
//                            cnt += 1;
//                        }
//                        if(c%2 == 0 && graph[i+r-1][j+c-1] != 'B'){
//                            cnt += 1;
//                        }
//                    }
//                    else{//짝수 행
//                        if(c%2 == 1 && graph[i+r-1][j+c-1] != 'B'){//홀수 열
//                            cnt += 1;
//                        }
//                        if(c%2 == 0 && graph[i+r-1][j+c-1] != 'W'){
//                            cnt += 1;
//                        }
//                    }
                
            }
            cnt = min(cnt, 64-cnt);
            if(ans > cnt){
                ans = cnt;
            }
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
