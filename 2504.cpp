//
//  2504.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 26..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <string.h>
#include <stack>

using namespace std;

int main(){
    char str[31];
    scanf("%s",str);
    
    stack<char> s;
    
    printf("%s len : %d\n",str, strlen(str));
    
    int ans = 0;
    
    int len = (int)strlen(str);
    for(int i=0; i<len; i++){
        int temp = 1;
        
        if(str[i] == '(' || str[i] == '['){
            s.push(str[i]);
        }
        else if(str[i] == ')'){
            if(!s.empty()){
                if(s.top() != '('){ //exception
                    printf("%d\n",0);
                    return 0;
                }
                else{ // ()
                    temp *= 2;
                    
                }
            }
            else{
                printf("%d\n",0);
                return 0;
                //s is empty
            }
        }
        else if(str[i] == ']'){
            if(!s.empty()){
                if(s.top() != '['){ //exception
                    printf("%d\n",0);
                    return 0;
                }
                else{ // []
                    
                }
            }
            else{
                //s is empty
                printf("%d\n",0);
                return 0;
            }
        }
    }
    
    return 0;
}
