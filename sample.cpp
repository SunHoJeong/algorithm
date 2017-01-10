//
//  1850.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 6..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>

using namespace std;

long long Eucle(long long a, long long b){
    long long remain;
    remain = b%a;
    
    if(remain == 0){
        return a;
    }
    else{
        return Eucle(remain, a);
    }
}


int main(){
    long long first;
    long long second;
    scanf("%lld %lld", &first, &second);
    
    long long big;
    long long small;
    
    if(first < second){ //first가 작은것
        small = first;
        big = second;
    }
    else{
        small = second;
        big = first;
    }
    long long gcm = Eucle(small, big);
    //printf("%lld, %lld\n", big, small);
    //printf("%lld\n", small);
    //printf("%lld\n", big);
    
    while(gcm--){
        printf("%d",1);
    }
    printf("\n");
    return 0;
    
}
