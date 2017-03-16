//
//  1920.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 16..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int search(int x, vector<int> v){
    int left = 0;
    int right = n-1;
    int mid;
    
    while(left<=right){
        mid = (left+right)/2;

        if(v[mid] == x){
            return 1;
        }
        else if(v[mid] > x){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    
    return 0;
}

int main(){
    
    scanf("%d",&n);
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
        scanf("%d",&v[i]);
    }
    sort(v.begin(), v.end());
    
    for(int i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    
    int m;
    scanf("%d",&m);
    for(int i=0; i<m; i++){
        int input;
        scanf("%d",&input);
        if( v[0] <= input && input <= v[n-1]){
            printf("%d\n",search(input, v));
        }
        else{
            printf("%d\n", 0);
        }
        
    }
    
    
    return 0;
}
