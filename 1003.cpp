//
//  1003.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 1..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>

using namespace std;

int result[2];

int f(int x){
    if(x==0){
        result[0] ++;
        return 0;
    }
    else if(x==1){
        result[1] ++;
        return 1;
    }
    else{
        return f(x-1)+f(x-2);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    
    while(t--){
        int n;
        scanf("%d",&n);
        result[0] = 0;
        result[1] = 0;
        
        f(n);
        
        printf("%d %d\n",result[0], result[1]);
        
    }
    return 0;
}
