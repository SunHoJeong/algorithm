//
//  1932.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 26..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int d[501][501];
int arr[501][501];
int main(){
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cin >> arr[i][j];
        }
    }
    
//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=n; j++){
//            cout << arr[i][j] <<" ";
//        }
//        cout << "\n";
//    }
    
    d[1][1] = arr[1][1];
    
    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(j==1){
                d[i][j] = d[i-1][j] + arr[i][j];
            }
            else if(j==i){
                d[i][j] = d[i-1][j-1] + arr[i][j];
            }
            else{
                d[i][j] = max(d[i-1][j-1], d[i-1][j]) + arr[i][j];
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(ans < d[n][i]){
            ans = d[n][i];
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
