//
//  1874.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 25..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>

using namespace std;

int a[100001];
int s[200001];
char result[200001];
int top =0;

void push(int n)
{
    s[++top] = n;
}

int pop(){
    if(top > 0){
        return s[top--];
    }
    else{
        return -1;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    
    int pos = 0; //+,- 저장하는 배열 point
    int temp = 1;
    for(int i=0; i<n; i++){
        if(temp <= a[i]){//1,4
            for(int k=temp; k<=a[i]; k++){//1234
                push(k);
                result[pos++] = '+';
                temp +=1 ;
            }
            
        }
        else{
            if(s[top] != a[i]){
                printf("NO\n");
                
                return 0;
            }
        }
        
        pop();
        result[pos++] = '-';
    }
    
    for(int i=0; i<pos; i++){
        printf("%c\n", result[i]);
    }
    
    
    return 0;
}
