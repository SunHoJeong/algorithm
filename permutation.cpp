//
//  permutation.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 17..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int n;
int arr[10] = {0,};
int result[10] = {0,};
bool visited[10] = {false,};

void dfs(int depth){
    
    if(depth == n){
        for(int i=0; i<n; i++){
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            result[depth] = i;
            dfs(depth++);
            visited[i] = false;
            result[i] = -1;
        }
    }
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        arr[i] = i;
    }
    
    
    dfs(0);
    
    
    
}
