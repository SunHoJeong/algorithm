//
//  bubble_sort.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 6. 17..
//  Copyright © 2017년 수노. All rights reserved.
//

/*
 selection sort
 O(n^2)
 앞에서부터 정렬
 */

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v = {27,5,11,4,15,3,9,8,7,12,2,21,1};

void sort(){
    int len = v.size();
    
    for(int i=0; i<len-1; i++){
        int max = i;
        for(int j=i+1; j<len; j++){
            if(v[j] < v[max]){
                max = j;
            }
        }
        
        int temp = v[i];
        v[i] = v[max];
        v[max] = temp;
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
