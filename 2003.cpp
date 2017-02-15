//
//  2003.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 15..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int a[10005];
int main(){
    int n,m;
    cin >> n>> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    int back = 1;
    int sum = 0;
    int cnt = 0;
    
    
    for(int front=1; front<=n; front++){
        sum += a[front];
        
        while(sum > m){
            sum -= a[back++];
        }
        if(sum == m)
            cnt += 1;
        
    }
    
    cout << cnt << "\n";
    return 0;
}
