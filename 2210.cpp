//
//  2210.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 2..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>

using namespace std;
const int N = 5;

char graph[6][6];
int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
set<string> s;

void back(int r, int c, int depth, string str){
    if(depth == 6){
        s.insert(str);
        return ;
    }
    
    str.append(1, graph[r][c]);
    
    for(int i=0; i<4; i++){
        int rr = r+dir[i][0];
        int cc = c+dir[i][1];
        
        if(rr <= 0 || rr > N || cc <= 0 || cc > N)
            continue;
        back(rr, cc, depth+1, str);
    }
}

int main(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> graph[i][j];
        }
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            back(i, j, 0, "");
        }
    }
    
    cout << s.size() << "\n";
    
    
    return 0;
}
