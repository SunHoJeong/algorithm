//
//  1182.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 27..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int a[22];
int n,s;
int cnt=0;

void power_set(int index, int sum){
    if(index > n){
        if(sum == s){
            cnt ++;
        }
        return;
    }
    
    power_set(index+1, sum);
    power_set(index+1, sum+a[index]);
}

int main(){
    
    cin >> n >> s;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    power_set(1, 0);
    
    if(s==0)
        cnt --;
    cout << cnt << "\n";
    return 0;
}
