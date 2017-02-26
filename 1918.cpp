//
//  1918.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 27..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;

stack<char> s;

int main(){
    char str[100];
    scanf("%s", str);
    
    int len = (int)strlen(str);
    
    for(int i=0; i<len; i++){
        if(str[i] == '('){
            s.push(str[i]);
        }
        else if(str[i] == ')'){
            while(!s.empty() && s.top() != '('){
                printf("%c", s.top());
                s.pop();
            }
            if(s.top() == '(')
                s.pop();
        }
        else if(65 <= str[i] && str[i] <=90){//A to Z
            printf("%c", str[i]);
        }
        else if(str[i] == '+' || str[i] == '-'){
            while(!s.empty() && s.top() != '('){
                printf("%c", s.top());
                s.pop();
            }
            s.push(str[i]);
        }
        else if(str[i] == '*' || str[i] == '/'){
            while(!s.empty() && s.top() != '+' && s.top() != '-' && s.top() != '('){
                printf("%c", s.top());
                s.pop();
            }
            s.push(str[i]);
        }
    }
    
    while(!s.empty()){
        printf("%c",s.top());
        s.pop();
    }
    
    return 0;
}
