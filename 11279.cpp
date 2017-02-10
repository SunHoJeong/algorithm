//
//  11279.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 10..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;
priority_queue<int> q;

int main(){
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        int cmd;
        cin >> cmd;
        
        if(cmd == 0){
            if(q.empty()){
                cout << 0 << "\n";
            }
            else{
               cout << q.top() << "\n";
                q.pop();
            }
        }
        else{
            q.push(cmd);
        }
    }
    return 0;
}
