//
//  1697.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 16..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

bool visited[100001] = {false,};
int value[100001] = {0,};
queue<int> q;

void sol(int des){
    while(!q.empty()){
        int st = q.front();
        q.pop();
        //printf("st:%d\n", st);
        
        if(st-1 >= 0 && !visited[st-1] ){
            visited[st-1] = true;
            value[st-1] = value[st]+1;
            if((st-1) == des){
                printf("%d\n",value[st-1]);
                return;
            }
            
            q.push(st-1);
            //printf("push%d\n",st-1);
        }
        if(st+1 <= 100000 && !visited[st+1]){
            visited[st+1] = true;
            value[st+1] = value[st]+1;
            if((st+1) == des){
                printf("%d\n",value[st+1]);
                return;
            }
            q.push(st+1);
            //printf("push%d\n",st+1);

        }
        if(st*2 <=100000 && !visited[st*2]){
            visited[st*2] = true;
            value[st*2] = value[st]+1;
            if((st*2) == des){
                printf("%d\n",value[st*2]);
                return;
            }
            q.push(st*2);
            //printf("push%d\n",st*2);

        }

    }
}

int main(){
    int n, k;
    
    scanf("%d %d", &n, &k);
    
    q.push(n);
    visited[n] = true;
    value[n] = 0;
    if(n == k){
        printf("%d\n",0);
        return 0;
    }
    sol(k);
    
    return 0;
}
