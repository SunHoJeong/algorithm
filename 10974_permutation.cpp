//
//  10974_permutation.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 1..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int arr[10];
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        arr[i] = i+1;
    }
    
    do{
        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }while(next_permutation(arr, arr+n));
    
    return 0;
}
