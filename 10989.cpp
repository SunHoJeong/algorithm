//
//  10989.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 19..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>


using namespace std;

int cnt[10001];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int temp;
        scanf("%d", &temp);
        cnt[temp] += 1;
    }
    
    for(int i=1; i<=10000; i++){
        for(int j=1; j<=cnt[i]; j++){
            printf("%d\n",i);
        }
    }
    
    return 0;
    
}
