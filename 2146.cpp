//
//  2146.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 13..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>

using namespace std;

int graph[101][101]={0,};

int main(){
    int n;
    scanf("%d",&n);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", graph[i][j]);
        }
    }
}
