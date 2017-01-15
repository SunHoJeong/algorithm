//
//  1991.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 13..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
using namespace std;

int arr[50][2];

void preorder(int node){
    if(node == -1){
        return;
    }
    cout << (char)('A'+node);
    preorder(arr[node][0]);
    preorder(arr[node][1]);
}

void inorder(int node){
    if(node == -1){
        return;
    }
    inorder(arr[node][0]);
    cout << (char)('A'+node);
    inorder(arr[node][1]);
}

void postorder(int node){
    if(node == -1){
        return;
    }
    postorder(arr[node][0]);
    postorder(arr[node][1]);
    cout << (char)('A'+node);
}

int main(){
    int n;
    cin >> n ;
    for(int i=1; i<=n; i++){
        char a, left, right;
        cin >> a >> left >> right;
        a = a-'A';
        
        if(left == '.'){
            arr[a][0] = -1;
        }
        else{
            arr[a][0] = left - 'A';
        }
        
        if(right == '.'){
            arr[a][1] = -1;
        }
        else{
            arr[a][1] = right - 'A';
        }
    }
    
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
    cout << "\n";
    
    return 0;
    
    
}
