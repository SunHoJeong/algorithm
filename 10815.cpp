//
//  10815.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 7. 29..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void binarySearch(vector<int> &v, int x){
    int left = 0;
    int right = v.size()-1;
    int mid = 0;
    
    while(left <= right){
        mid = (left + right)/2;
        
        if(v[mid] == x){
            printf("%d ", 1);
            return;
        }
        else if(v[mid] > x){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    
    printf("%d ", 0);
    return;
}

int main(){
    int m;
    int n;
    scanf("%d", &m);
    vector<int> v(m+1);
    
    for(int i=0; i<m; i++){
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    
    scanf("%d", &n);
    
    int smallest = v[0];
    int bigest = v[v.size()-1];
    
    for(int i=0; i<n; i++){
        int target=0;
        scanf("%d", &target);
        if(smallest <= target && target <= bigest){
                binarySearch(v, target);
        }
        else{
            printf("%d ", 0);
        }
    }
    
    printf("\n");
    
    return 0;
}
