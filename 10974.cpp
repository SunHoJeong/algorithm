//
//  10974.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 1..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int n;
int result[10];
bool visited[10];

void permutation(int depth){
    if(depth == n){
        for(int i=0; i<n; i++){
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            result[depth] = i;
            visited[i] = true;
            permutation(depth+1);
            visited[i] = false;
        }
    }
}

int main(){
    
    cin >> n;
    
    permutation(0);
    
    return 0;
}
