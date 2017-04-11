//
//  1.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 7..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int d[1000001];

int main(){
    int n;
    cin >> n;
    
    d[1] = 0;
    for(int i=2; i<=n; i++){
        d[i] =d[i-1]+1;
        if(i%2==0){
            int temp = d[i/2] +1;
            if(d[i] > temp){
                d[i] = temp;
            }
        }
        if(i%3==0){
            
        }
    }
    
    cout << d[n] << "\n";
    return 0;
}
