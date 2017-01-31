//
//  10972.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 31..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAX = 10001;
int n;
int input[MAX];
int result[MAX];
bool visited[MAX];
bool check = false;

void sol(int x, int depth){
    if(depth == n){
        if(check){
            for(int i=0; i<n; i++){
                cout << result[i] << " ";
            }
            cout << "\n";
            check = false;
            return;
        }
        
        for(int i=0; i<n; i++){
            if(result[i] == input[i]){
                if(i == n-1){
                    //cout << "실행" << "\n";
                    check = true;
                    return;
                }
                continue;
            }
            else{
                return;
            }
        }
        
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            result[depth] = i;
            sol(i, depth+1);
            result[depth] = -1;
            visited[i] = false;
        }
    }
    
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> input[i];
    }
    
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            result[0] = i;
            sol(i, 1);
            result[0] = -1;
            visited[i] = false;
        }
        
    }
    if(check){
        cout << -1 << "\n";
    }
    return 0;
}
