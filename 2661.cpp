//
//  2661.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 5..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

int n;

void back(int depth, vector<char> v){
    //printf("--dep:%d\n",depth);
    if(depth == n-1){
        for(char c: v){
            printf("%c", c);
        }
        printf("\n");
        exit(0);
        return;
    }
    
    for(int i=1; i<=3; i++){
        if(v[depth] == i+'0'){
            //printf("dep:%d i:%d\n",depth, i);
            continue;
        }
        if(depth >= 2){
            if(v[depth-1] == i+'0' && v[depth] == v[depth-2])
                continue;
        }
        if(depth >= 4){
            if(v[depth-2] == i+'0' && v[depth-3] == v[depth]
               && v[depth-1] == v[depth-1])
                continue;
        }
        v[depth+1] = i+'0';
        back(depth+1, v);

    }
}

int main(){
    scanf("%d", &n);
    vector<char> v(n+1);
    
    for(int i=1; i<=3; i++){
        v[0] = i+'0';
        back(0, v);
    }
    
    return 0;
}
