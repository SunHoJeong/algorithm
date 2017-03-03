//
//  1149.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 1..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int graph[1001][3];
int d[1001][3];

int main(){
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            cin >> graph[i][j];; //i번째집을 빨초파로 칠하는 비용
        }
    }
    for(int i=0; i<3; i++){
        d[1][i] = graph[1][i];
    }
    
    for(int i=2; i<=n; i++){
        d[i][0] = min(d[i-1][1], d[i-1][2]) + graph[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + graph[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + graph[i][2];
    }
    
    int min = 1000000000;
    for(int i=0; i<3; i++){
        if(d[n][i] < min){
            min = d[n][i];
        }
    }
    cout << min << "\n";
    
    return 0;
}
