//
//  9935.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 28..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

char s[1000001];
int top = -1;

bool isEmpty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}

void push(char a){
    s[++top] = a;
}

char pop(){
    if(top >= 0){
        return s[top--];
    }
    else{
        return NULL;
    }
}

int main(){
    char str[1000001];
    char bomb[40];
    
    scanf("%s", str);
    scanf("%s", bomb);
    
    int str_len = (int)strlen(str);
    int bomb_len = (int)strlen(bomb);
    //printf("%d %d\n",str_len, bomb_len);
    for(int i=0; i<str_len; i++){
        //printf("%d -> %c\n",i,str[i]);
        push(str[i]);
        
        //printf("%c %c\n",s[top], bomb[bomb_len]);
        if(s[top] == bomb[bomb_len-1]){//stack의 top에 있는 것과 bomb 맨 뒤 문자가 같으면
            int temp = 0;
            for(int j=bomb_len-1; j>=0; j--){
                if(top-temp>=0 && s[top-temp] == bomb[j]){
                    if(j==0){
                        for(int k=1; k<=bomb_len; k++){
                            pop();
                        }
                    }
                }
                else{
                    break;
                }
                temp++;
            }
            
        }
    }
    
    
    if(isEmpty()){
        printf("FRULA\n");
    }
    else{
        int size = top+1;
        vector<char> v(top);
        while(!isEmpty()){
            v.push_back(pop());
        }
        
        reverse(v.begin(), v.end());
        for(int i=0; i<size; i++){
            printf("%c",v[i]);
        }
        printf("\n");
    }
    
    
    return 0;
}
