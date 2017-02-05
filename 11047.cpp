//
//  11047.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 5..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int n,k;

int main(){
    cin >> n >> k;
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int index = n-1;
    int sum = 0;
    int cnt = 0;
    while(index >-1){
        if(sum + v[index] > k){
            index = index -1;
        }
        else{
            sum += v[index];
            cnt += 1;
        }
    
    }
    
    cout << cnt << "\n";
    return 0;
}
