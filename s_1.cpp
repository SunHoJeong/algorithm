//
//  s_1.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 6. 30..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

struct Data{
    int n;
    char c;
}data;

Data stack[100000];
int top = -1;

Data pop(){
    return stack[top--];
}

void push(Data d){
    stack[++top] = d;
}

int main(){
    int t=0;
    cin >> t;
    
    for(int k=1; k<=t; k++){
        int answer = 0;
        string input;
        cin >> input;
        
        for(int i=0; i<input.size(); i++){
            if(input[i] == '(' || input[i] == '{' || input[i] == '['){
                Data d;
                d.c = input[i];
                //d.n = -1;
                push(d);
            }
            else if(input[i] == ')'){
                if(top >= 0){
                    if(stack[top].c == '(' || stack[top].c == '{' || stack[top].c || '['){
                        if(stack[top].c == '('){
                            Data temp = pop();
                            if(top >= 0){
                                if(stack[top].n != -1){
                                    stack[top].n += 2;
                                }
                                else{
                                    Data d;
                                    d.n = 2;
                                    push(d);
                                }
                            }
                        }
                    }
                    else{//int
                        
                    }
                }
            }
        }
        
        
        cout << "Case #"<< k <<"\n";
        cout << answer <<"\n";
        
    }
    return 0;
}
