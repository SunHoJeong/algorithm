//
//  1929.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 6..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>

using namespace std;

int arr[1000001] = {0,};
int m,n;
bool check[10000001];

int main(){
    check[0] = check[1] = true;
    
    scanf("%d %d", &m, &n);
    
    for(int i=2; i*i <= 1000000; i++){
        if(check[i] == false){
            for(int j= i+i; j<=1000000; j += i){
                check[j] =true;
            }
//            int temp = i;
//            while(temp <= 1000000){
//                printf("%d\n", temp);
//                check[temp] = true;
//                temp += temp;
//            }
        }
    }
    
    for(int i=m; i<=n; i++){
        if(check[i] == false){
            printf("%d\n", i);
        }
    }
    return 0;
}
