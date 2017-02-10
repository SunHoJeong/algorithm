//
//  1927_min_heap.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 10..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

//struct compare{
//    bool cmp()(int u, int v){
//        return u>v;
//    }
//};

int main(){
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        int cmd;
        cin >> cmd;
        if(cmd == 0){
            if(min_heap.empty()){
                cout << 0 << "\n";
            }
            else{
                cout << min_heap.top() << "\n";
                min_heap.pop();
            }
        }
        else{
            min_heap.push(cmd);
        }
    }
    
    
    return 0;
}
