//
//  1978.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 5..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>

using namespace std;

int prime[1001];

int main(){
    prime[1] = true;
    for(int i=2; i*i<=1001; i++){
        if(!prime[i]){
            for(int j=i+i; j<=1001; j += i){
                prime[j] = true;
            }
        }
    }
    
    int n;
    int ans=0;
    scanf("%d", &n);
    for(int k=1; k<=n; k++){
        int num;
        scanf("%d", &num);
        if(!prime[num])
            ans++;
            
    }
    
    printf("%d\n",ans);
    return 0;
}
