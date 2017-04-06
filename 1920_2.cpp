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
int input[100001];
int ans[100001];

int search(int x, int* v){
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
    
    for(int i=0; i<n; i++){
        scanf("%d",&input[i]);
    }
    sort(input, input+n);
    
    int m;
    scanf("%d",&m);
    for(int i=0; i<m; i++){
        scanf("%d",&ans[i]);
    }
    
    for(int i=0; i<m; i++){
        int searchNum = ans[i];
        printf("%d\n",search(searchNum, input));
    }
    
    
    return 0;
}
