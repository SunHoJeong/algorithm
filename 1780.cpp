//
//  1780.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 9. 5..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int graph[2500][2500];
int paper[3];

bool same(int x, int y, int n){
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(graph[i][j] != graph[x][y]){
                return false;
            }
        }
    }
    
    return true;
}

void sol(int x, int y, int n){
    if(same(x,y,n)){
        paper[graph[x][y]+1] += 1;
        return;
    }
    
    int m = n/3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            sol(x+i*m, y+j*m, m);
        }
    }
}

int main(){
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> graph[i][j];
        }
    }
    
    sol(0, 0, n);
    
    for(int i=0; i<3; i++){
        cout << paper[i] << "\n";
    }
    
    return 0;
}
