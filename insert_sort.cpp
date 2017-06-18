//
//  insert_sort.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 6. 18..
//  Copyright © 2017년 수노. All rights reserved.
//

/*
 insert sort
 O(n^2)
 */

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v = {27,5,11,4,15,3,9,8,7,12,2,21,1};

void sort(){
    int len = v.size();
    int j=0;
    
    for(int i=1; i<len; i++){
        int insNum = v[i];
        
        for(j= i-1; j>=0; j--){
            if(v[j] > insNum){
                v[j+1] = v[j];
            }
            else
                break;
        }
        
        v[j+1] = insNum;
    }
}

int main(){
    cout << "정렬 전\n";
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
    
    sort();
    
    cout << "정렬 후\n";
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
