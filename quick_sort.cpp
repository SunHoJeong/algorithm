//
//  quick_sort.cpp
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

void swap(int arr[], int idx1, int idx2){
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
    
}

int Partition(int arr[], int left, int right){
    int pivot = arr[left];
    int low = left+1;
    int high = right;
    
    while(low <= high){
        //while(pivot > arr[low])
        while(pivot >= arr[low] && low <= right)
            low++;
        
        //while(pivot < arr[high])
        while(pivot <= arr[high] && left+1 <= high)
            high--;
        
        if(low <= high)
            swap(arr, low, high);
    }
    
    //pivot index <-> high index
    //pivot을 기준으로 작음 pivot 큼 -> partition
    swap(arr, left, high);
    
    
    return high;
}

void quickSort(int arr[], int left, int right){
    if(left <= right){
        //divide and conquer
        int pivot  = Partition(arr, left, right);
        
        quickSort(arr, left, pivot-1);
        quickSort(arr, pivot+1, right);
        
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
    
    quickSort(arr, 0, len-1);
    
    cout << "정렬 후\n";
    for(int i=0; i<len; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
