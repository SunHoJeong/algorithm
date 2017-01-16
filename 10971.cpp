//
//  10971.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 16..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int graph[11][11] = {0,};
int visited[11][11] = {false,};

int main(){
    int n;
    int min = 123456789;

    scanf("%d", &n);
    vector<int> v(n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        v[i] = i+1;
    }
    
    do{
        int temp_sum = 0;
        bool ok = true;
        for(int i=0; i<n-1; i++){
            if(graph[v[i]][v[i+1]] == 0){
                ok = false;
            }
            else{
                temp_sum += graph[v[i]][v[i+1]];
            }
            
        }
        if(ok && graph[v[n-1]][v[0]] != 0){
            //printf("temp_sum_%d\n",temp_sum);

            temp_sum += graph[v[n-1]][v[0]];
            if(min > temp_sum){
                min = temp_sum;
            }
        }
        
    }while(next_permutation(v.begin(), v.end()));
    
    printf("%d\n", min);
    return 0;
}
