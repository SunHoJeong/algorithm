//
//  2309.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 27..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <stdlib.h>
using namespace std;

const int N = 7;
const int SUM = 100;
int a[15];
int result[15];
bool visited[15];

void sol(int index, int depth, int sum){
    if(index > 10)
        return;
    if(N == depth){
        if(sum == SUM){
            sort(result, result+N);
            for(int i=0; i<N; i++){
                printf("%d\n", result[i]);
            }
            exit(0);
        }
        return;
    }
    if(!visited[index]){
        result[depth] = a[index];
        visited[index] = true;
        sol(index+1, depth+1, sum+a[index]);
        result[depth] = 0;
        visited[index] = false;
        sol(index+1, depth, sum);
    }
    
}

int main(){
    for(int i=0; i<9; i++){
        scanf("%d",&a[i]);
    }
    
    sol(0, 0, 0);
    
    return 0;
}
