//
//  1655.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 20..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<int>> max_heap; //left
priority_queue<int, vector<int>, greater<int>> min_heap; //right


int main(){
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        int input;
        scanf("%d", &input);
        
        if(max_heap.size() == min_heap.size()){ //push left
            if(max_heap.size() == 0 && min_heap.size() == 0){
                max_heap.push(input); //init
            }
            else{
                if(min_heap.top() < input){
                    int temp = min_heap.top();
                    min_heap.pop();
                    min_heap.push(input);
                    max_heap.push(temp);
                    
                }
                else{
                    max_heap.push(input);
                }
            }
        }
        else if(max_heap.size() > min_heap.size()){//push right
            if(max_heap.top() > input){
                int temp = max_heap.top();
                max_heap.pop();
                max_heap.push(input);
                min_heap.push(temp);
            }
            else{
                min_heap.push(input);
            }
        }
        printf("%d\n", max_heap.top());
        
    }
    
//    while(!max_heap.empty()){
//        cout << max_heap.top() << " ";
//        max_heap.pop();
//    }
//    
//    cout << "\n";
//    
//    while(!min_heap.empty()){
//        cout << min_heap.top() << " ";
//        min_heap.pop();
//    }
    
    return 0;
}
