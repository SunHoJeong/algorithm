//
//  1158.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 4..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

int main(){
    int n;
    int m;
    queue<int> queue;
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        queue.push(i);
    }
    printf("<");
    while(!queue.empty()){
        for(int i=1; i<=m; i++){
            if(i ==m ){
                printf("%d",queue.front());
                queue.pop();
                if(!queue.empty()){
                    printf(", ");
                }
            }
            else{
                int temp = queue.front();
                queue.pop();
                
                queue.push(temp);
            }
            
        }
    }
    printf(">");
    
}
