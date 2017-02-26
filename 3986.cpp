//
//  3986.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 27..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <stack>
#include <string.h>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    
    int cnt = 0;
    for(int k=1; k<=t; k++){
        char input[100005];
        scanf("%s", input);
        
        stack<char> s;
        int len = (int)strlen(input);
        
        for(int i=0; i<len; i++){
            if(s.empty()){
                s.push(input[i]);
            }
            else{
                if(input[i] == s.top()){
                    s.pop();
                }
                else{
                    s.push(input[i]);
                }
            }
            
        }
        if(!s.empty()){
            cnt += 1;
        }
    }
    
    printf("%d\n", t-cnt);
    return 0;
}
