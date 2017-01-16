//
//  1476.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 16..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>

using namespace std;

int main(){
    int e,s,m;
    int temp1, temp2, temp3;
    int cnt = 1;
    scanf("%d %d %d",&e, &s, &m);
    temp1 = temp2 = temp3 = 1;
    
    for(int i=1; i<=15; i++){
        for(int j=1; j<=28; j++){
            for(int k=1; k<=19; k++){
                //printf("%d %d %d\n",temp1, temp2, temp3);
                if(temp1==e && temp2==s && temp3==m){
                    printf("%d\n",cnt);
                    return 0;
                }
                else{
                    temp1 = temp1%15 +1;
                    temp2 = temp2%28 +1;
                    temp3 = temp3%19 +1;
                    cnt++;
                }
            }
        }
    }
    
    return 0;
}
