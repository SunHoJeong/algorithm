//
//  2665.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 4..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int graph[52][52];
bool visited[52][52];
int d[52][52];
int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
int n;

void sol(int r, int c, int cnt){
    //cout << "sol: " << r << "," << c <<"\n";
    if(graph[r][c] == 1)
        cnt++;
    
    d[r][c] = cnt;
    if(r == n && c == n){
        return;
    }
    
    for(int i=0; i<4; i++){
        int rr = r+dir[i][0];
        int cc = c+dir[i][1];
        //cout << rr << "," << cc << "\n";
        if(0 < rr && rr <=n && 0 < cc && cc <= n && d[rr][cc] > cnt){
            sol(rr, cc, cnt);
        }
    }
}

int main(){
    cin >>n;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            d[i][j] = 9999;
        }
    }
    
    for(int i=1; i<=n; i++){
        string str;
        cin >> str;
        for(int j=0; j<str.size(); j++){
            if(str[j] == '1'){
                graph[i][j+1] = 0;
            }
            else{
                graph[i][j+1] = 1;
            }
        }
    }
    
    sol(1,1,0);

    cout << d[n][n] << "\n";
    
    
    return 0;
}
