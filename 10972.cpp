//
//  10972.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 31..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int arr[100001];
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    if(next_permutation(arr, arr+n)){
        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    else{
        cout << -1 << "\n";
    }
    
    return 0;
}
