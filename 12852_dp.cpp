//
//  12852.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 7..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>

using namespace std;

int d[1000001];
int from[1000001];

int main(){
    int n;
    scanf("%d",&n);
    
    d[0] = 0;
    d[1] = 0;
    from[1] = -1;
    for(int i=2; i<=n; i++){
        d[i] =d[i-1]+1;
        from[i] = i-1;
        if(i%2==0){
            int temp = d[i/2] +1; //d[4] = d[2]+1
            if(d[i] > temp){
                d[i] = temp;
                from[i] = i/2;
            }
        }
        if(i%3==0){
            int temp = d[i/3] +1;
            if(d[i] > temp){
                d[i] = temp;
                from[i] = i/3;
            }
        }
    }
    
    printf("%d\n", d[n]);
    printf("%d ",n);
    while(from[n] != -1){
        printf("%d ", from[n]);
        n = from[n];
    }
    
    return 0;
}
