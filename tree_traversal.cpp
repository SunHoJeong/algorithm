//
//  tree_traversal.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 31..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
using namespace std;

int tree[27][2];

void preorder(int x){
    if(x == -1){
        return;
    }
    cout << (char)(x+'A');
    preorder(tree[x][0]);
    preorder(tree[x][1]);
}

void inorder(int x){
    if(x == -1){
        return;
    }
    inorder(tree[x][0]);
    cout << (char)(x+'A');
    inorder(tree[x][1]);

}

void postorder(int x){
    if(x== -1){
        return;
    }
    postorder(tree[x][0]);
    postorder(tree[x][1]);
    cout << (char)(x+'A');
    
}
int main(){
    int node;
    cin >> node;
    
    for(int i=0; i<node; i++){
        char parent, child1, child2;
        cin >> parent >> child1 >> child2;
        
        if(child1 != '.'){
            tree[parent-'A'][0] = child1-'A';
        }
        else{
            tree[parent-'A'][0] = -1;
        }
        if(child2 != '.'){
            tree[parent-'A'][1] = child2-'A';
        }
        else{
            tree[parent-'A'][1] = -1;
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
