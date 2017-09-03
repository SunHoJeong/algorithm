//
//  11047_2.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 9. 3..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int coinArr[11];
int d[10000];

int main(){
    int n;
    int sum;
    cin >> n >> sum;
    
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    int answer = 0;
    for(int i = n-1; i>=0; i--){
        answer += sum/v[i];
        sum %= v[i];
    }
    
    cout << answer << "\n";

    return 0;
}
