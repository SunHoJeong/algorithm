//
//  disjoint_set.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 15..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int p[100];

int Find(int x){ // x의 parent 찾기
    if(x == p[x]){
        return x;
    }
    else{
        return p[x] = Find(p[x]);
    }
}

void Union(int a, int b){ //b의 parent 를 a로
    a = Find(a);
    b = Find(b);
    
    p[b] = a;
}

int main(){
    int n=10;
    
    for(int i=1; i<=n; i++){//p배열 초기화
        p[i] = i;
    }
    
    return 0;
}
