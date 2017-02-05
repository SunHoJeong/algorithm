//
//  2294.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 3..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;
int d[10001];
int a[101];
int n,k;

int main(){
    
    cin >> n >> k;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=10001; i++){
        d[i] = 100001;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=a[i]; j<=k; j++){
            d[j] = min(d[j], d[j-a[i]] + 1);
        }
    }
    
    if(d[k] == 100001){
        cout << -1 << "\n";
    }
    else{
        cout << d[k] << "\n";
    }
    
    return 0;
}
