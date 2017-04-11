//
//  11403_floyd_warshall.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 11..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>

int n;
int graph[105][105];
int d[105][105];
int main(){
    
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
            d[i][j] = 0;
        }
    }
   
    for(int k=0 ; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(graph[i][k] == 1 && graph[k][j] == 1){
                    graph[i][j] = 1;
                }
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}
