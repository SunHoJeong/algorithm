//
//  10448.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 27..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>

using namespace std;

int tri[100];
int n=1;

int main(){
    
    while(n*(n+1)/2 <= 1000){
        tri[n] = n*(n+1)/2;
        n++;
    }
    tri[n] = n*(n+1)/2;
    
    int t;
    scanf("%d", &t);
    
    for(int a=1; a<=t; a++){
        int input;
        scanf("%d", &input);
        bool check = false;
        for(int i=1; i<=45; i++){
            if(check)
                break;
            for(int j=1; j<=45; j++){
                for(int k=1; k<=45; k++){
                    if(tri[i] + tri[j] + tri[k] == input){
                        check = true;
                    }
                }
            }
        }
        
        if(check){
            printf("%d\n",1);
        }
        else{
            printf("%d\n",0);
        }
        
    }
    
    return 0;
}
