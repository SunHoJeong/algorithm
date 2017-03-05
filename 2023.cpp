//
//  2023.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 2..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>

using namespace std;
const int MAX = 100000000;

bool prime[MAX]; //false면 소수
int n;

void back(int depth, int x){
    if(depth == n-1){
        printf("%d\n",x);
        return;
    }
    
    for(int i=0; i<=9; i++){
        if((x*10+i) < MAX && !prime[x*10+i]){
            back(depth+1, x*10+i);
        }
    }
}

int main(){
    prime[1] = true;
    for(int i=2; i*i<MAX; i++){
        if(!prime[i]){
            for(int j=i+i; j<MAX; j += i){
                prime[j] = true;
            }
        }
    }
    
    // 1 12 123 1234
    scanf("%d", &n);
    
    for(int i=1; i<=9; i++){
        if(!prime[i]){
            back(0, i);
        }
    }
    
    return 0;
}
