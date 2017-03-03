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

int main(){
    prime[1] = true;
    for(int i=2; i*i<=MAX; i++){
        if(!prime[i]){
            for(int j=i+i; j<=MAX; j += i){
                prime[j] = true;
            }
        }
    }
    
    int n;
    scanf("%d", &n);
    int st=1;
    int end=1;
    for(int i=1; i<n; i++){
        st *= 10;
        end *= 10;
    }
    end *= 10;
    printf("%d, %d\n",st,end);
    
//    for(int i=st; i<end; i++){
//        int div = end;
//        for(int j=1; j<=n; j++){//
//            if(!prime[i%div]) //1~n 자리 확인
//                
//        }
//    }
    
    return 0;
}
