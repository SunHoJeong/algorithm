//
//  2042.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 17..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long init(vector<long long> &v, vector<long long> &tree, int node, int start, int end){
    if(start == end){
        return tree[node] = v[start];
    }
    else{
        return tree[node] = init(v, tree, node*2, start, (start/end)/2)
        + init(v, tree, node*2+1, (start+end)/2+1, end);
    }
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff){
    if(index < start || index > end)
        return;
    tree[node] = tree[node]+diff;
    
    if(start != end){
        update(tree, node*2, start, (start+end)/2, index, diff);
        update(tree, node*2+1, (start+end)/2+1, end, index, diff);
    }
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right){
    if(left > end || right < start ){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    return sum(tree, node*2, start, (start+end)/2, left, right)
    + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}

int main(){
    int n, m, k; //m = 수의변경 횟수, k = 구간의 합을 구하는 횟수
    cin >> n >> m >> k;
    
    vector<long long> v(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 <<(h+1));
    vector<long long> tree(tree_size);
    for(int i=0; i<n; i++){
        cin >> v[i] ;
    }
    
    for(int i=1; i<= m+k; i++){
        long long a;
        cin >> a;
        
        if(a == 1){ // update 변경 b->c
            int b;
            long long c;
            cin >> b >> c;
            
            b -= 1;
            long long diff = c -v[b];
            v[b] = c;
             update(tree, 1, 0, n-1, b, diff);
        }
        else if(a == 2){ // 합 sum b~c
            int b,c;
            cin >> b >> c;
            cout << sum(tree, 1, 0, n-1, b-1, c-1) << "\n";
        }
    }
    
    return 0;
}
