//
//  11048.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 15..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int graph[1005][1005];
int d[1005][1005];

int main(){
    int row,col;
    cin >> row >> col;
    
    for(int i=0; i<=row+1; i++){
        for(int j=0; j<=col+1; j++){
            graph[i][j] = -1;
        }
    }
    
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            cin >> graph[i][j];
        }
    }
    
    d[1][1] = graph[1][1];
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            d[i][j] = max(max(d[i-1][j], d[i-1][j-1]), d[i][j-1]) + graph[i][j];
        }
    }
    
    cout << d[row][col] << "\n";
    
    return 0;
}
