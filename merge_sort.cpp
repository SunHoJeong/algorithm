//
//  merge_sort.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 6. 18..
//  Copyright © 2017년 수노. All rights reserved.
//

/*
 merge sort
 O(NlongN)
 */

#include <iostream>

using namespace std;

int n;
//vector<int> v = {27,5,11,4,15,3,9,8,7,12,2,21,1};

void mergeTwo(int arr[], int left, int mid, int right){
    int fIdx = left;
    int rIdx = mid+1;
    
    int* sortArr = (int*)malloc(sizeof(int)*(right+1));
    int sIdx=left;
    
    while(fIdx <= mid && rIdx <= right){
        if(arr[fIdx] < arr[rIdx]){
            sortArr[sIdx] = arr[fIdx++];
        }
        else{
            sortArr[sIdx] = arr[rIdx++];
        }
        
        sIdx++;
    }
    
    if(fIdx>mid){
        for(int i=rIdx; i<=right; i++, sIdx++){
            sortArr[sIdx] = arr[i];
        }
    }
    
    if(rIdx>right){
        for(int i=fIdx; i<=mid; i++, sIdx++){
            sortArr[sIdx] = arr[i];
        }
    }
    
    for(int i=left; i<=right; i++){
        arr[i] = sortArr[i];
    }
    
    free(sortArr);
}

void mergeSort(int arr[], int left, int right){
    int mid;
    
    if(left < right){
        mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        
        mergeTwo(arr, left, mid, right);
    }
    
}

int main(){
    int arr[10] = {1,5,9,6,3,2,7,8,10,4};
    int len = sizeof(arr)/sizeof(int);
    
    cout << "정렬 전\n";
    for(int i=0; i<len; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    mergeSort(arr, 0, len-1);
    
    cout << "정렬 후\n";
    for(int i=0; i<len; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
