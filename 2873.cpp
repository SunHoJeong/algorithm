//
//  2873.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 9..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;
int graph[1002][1002];
bool visited[1002][1002];

int main(){
    int r,c;
    cin >> r >> c;
    for(int i=0; i<=r+1; i++){
        for(int j=0; j<=c+1; j++){
            graph[i][j] = -1;
        }
    }
    
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin >> graph[i][j];
        }
    }
    
    for(int i=0; i<=r+1; i++){
        for(int j=0; j<=c+1; j++){
            cout << graph[i][j] << " ";
        }
        cout <<"\n";
    }
    
    
    return 0;
}
