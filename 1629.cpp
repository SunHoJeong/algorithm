//
//  1629.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 3..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

long long a,b,c;
long long sol(long long x, long long n){
    if(n==0)
        return 1;
    
    if(n%2 == 1)
        return (x*sol(x, n-1))%c;
    else{
        long long temp = sol(x, n/2);
        return (temp * temp)%c;
    }
}

int main(){
    
    cin >> a >> b >> c ;
    
    long long ans=sol(a, b);
    cout << ans << "\n";
    return 0;
}
