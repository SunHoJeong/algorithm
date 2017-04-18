//
//  14501.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 17..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int a[16];
int day[16];
int d[16];
int n;

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> day[i] >> a[i];
    }
    
    d[0] = 0;
    for(int i=1; i<=n; i++){
        if((i+day[i]-1 <= n) && d[i+day[i]-1] < d[i-1] + a[i]){
            d[i+day[i]-1] = d[i-1] + a[i];
            for(int j = i+day[i]-1; j<=n; j++){
                if(d[j] < d[i-1]+a[i]){
                    d[j] = d[i-1] + a[i];
                }
            }
        }
    }
    
    cout << d[n] << "\n";
    return 0;
}
