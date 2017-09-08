//
//  2263.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 9. 8..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int in[100001];
int post[100001];
int position[100001];

void sol(int is, int ie, int ps, int pe){
    if(is > ie || ps > pe)
        return;
    
    int root = post[pe];
    int inRootPos = position[root];
    cout << root << " ";
    
    int leftNum = inRootPos-is;
    
    sol(is, inRootPos-1, ps, ps+leftNum-1);
    sol(inRootPos+1, ie, ps+leftNum, pe-1);
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> in[i];
        position[in[i]] = i;
    }
    for(int i=0; i<n; i++){
        cin >> post[i];
    }
    
    sol(0, n-1, 0, n-1);
    
    return 0;
}
