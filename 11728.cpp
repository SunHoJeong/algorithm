//
//  11728.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 9. 5..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int a[1000000];
int b[1000000];
int result[1000000];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    
    int fIdx = 0;
    int rIdx = 0;
    int k =0;
    
    while(fIdx < n && rIdx < m){
        if(a[fIdx] > b[rIdx]){
            result[k++] = b[rIdx++];
        }
        else{
            result[k++] = a[fIdx++];
        }
    }
    
    while(fIdx<n){
        result[k++] = a[fIdx++];
    }
    while(rIdx<m){
        result[k++] = b[rIdx++];
    }
    
    for(int i=0; i<n+m; i++){
        cout << result[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
