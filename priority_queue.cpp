//
//  priority_queue.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 9..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int main(){
    priority_queue<int> pri_q;
    
    for(int i=0; i<10; i++){
        int temp;
        cin >> temp;
        pri_q.push(temp);
    }
    
    while(!pri_q.empty()){
        cout << pri_q.top();
        pri_q.pop();
    }
    return 0;
}
