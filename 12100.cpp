//
//  12100.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 15..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <string.h>

int n;
int graph[21][21];
bool visited[21];

void sol(int (*map)[21], int depth){
    if(depth == 5){
        //find max
    }
    
    //left
    for(int i=0; i<n; i++){//row
        int pos = 0;
        memset(visited, false, sizeof(visited));
        
        for(int j=0; j<n; j++){//col
            
            if(graph[i][j] == graph[i][j+1]){
                if(graph[i][j] == 0)
                    continue;
                else{//두개가 같으면 합친다.
                    int temp = graph[i][j];
                    graph[i][j] = 0;
                    graph[i][j+1] = 0;
                    visited[pos] = true;
                    graph[i][pos++] = temp << 1;
                }
            }
            else if(graph[i][j] != graph[i][j+1]){
                printf("%d %d pos:%d\n",graph[i][j], graph[i][j+1],pos);
                if(graph[i][j] == 0){ // 0 X
                    int temp = graph[i][j+1];
                    if(pos-1 >=0 && !visited[pos-1] && graph[i][pos-1] == temp){
                        printf("1\n");
                        visited[pos-1] = true;
                        graph[i][j+1] = 0;
                        graph[i][pos-1] = graph[i][pos-1]*2;
                    }
                    else{
                        printf("2\n");
                        graph[i][j+1] = 0;
                        graph[i][pos++] = temp;
                    }
                }
                else if(graph[i][j+1] == 0){ // X 0
                    if(pos != j){
                        printf("pos:%d j:%d\n",pos,j);
                        int temp = graph[i][j];
                        graph[i][j] = 0;
                        graph[i][pos++] = temp << 1;
                    }
                    else{
                        printf("4\n");
                        pos ++;
                    }
                    
                }
                
            }
            
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    printf("%3d", graph[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            
        }
    }//left
    
    
    
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%3d", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    sol(graph, 0);
    
    return 0;
}
