//
//  2580.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 28..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>

using namespace std;

int graph[11][11];

bool promissing(int r, int c, int val){
    for(int i=1; i<=9; i++){
        if(i != c && graph[r][i] == val) //row
            return false;
        if(i != r && graph[i][c] == val) //col
            return false;
    }
    
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            if(i!=r || j!=c){
                if(graph[i][j] == val){
                    return false;
                }
            }
        }
    }
    
    
    return true;
}

void back(int r, int c){
    for(int k=1; k<=9; k++){
        graph[r][c] = k;
        if(promissing(r,c,k)){
        //i 가능
            if(r==9 && c==9){
                for(int i=1; i<=9; i++){
                    for(int j=1; j<=9; j++){
                        printf("%d ",graph[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            for(int i=1; i<=9; i++){
                for(int j=1; j<=9; j++){
                    if(graph[i][j] == 0){
                        back(i,j);
                    }
                }
            }
            
        }else{
            graph[r][c] = 0;
        }
        
    }
}

int main(){
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            if(graph[i][j] == 0){
                back(i,j);
                break;
            }
        }
    }
    
    
    return 0;
}
