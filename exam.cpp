
#include <iostream>
#include <vector>

using namespace std;

vector<int> v = {1,2,3,4,5,6,7,8,9};

void mergeTwo(int arr[], int left, int mid, int right){
    int fIdx = left;
    int rIdx = mid+1;
    int k = left;
    int tempArr[100];
    
    while(fIdx <= mid && rIdx <= right){
        if(arr[fIdx] <= arr[rIdx]){
            tempArr[k] = arr[fIdx++];
        }
        else{
            tempArr[k] = arr[rIdx++];
        }
        
        k++;
    }
    
    if(fIdx > mid){
        for(int i=rIdx; i<=right; i++, k++){
            tempArr[k] = arr[i];
        }
    }
    
    if(rIdx > right){
        for(int i=fIdx; i<=mid; i++, k++){
            tempArr[k] = arr[i];
        }
    }
    
    for(int i = left; i<=right; i++){
        arr[i] = tempArr[i];
    }
}

void mergeSort(int arr[], int left, int right){
    int mid = (left+right)/2;
    
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
}

int main(){
    int arr[10] = {1,5,9,6,3,2,7,8,10,4};
    int len = sizeof(arr)/sizeof(int);
    
    cout << "정렬 전\n";
    for(int i=0; i<len; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    //mergeSort(arr, 0, len-1);
    
    cout << "정렬 후\n";
    for(int i=0; i<len; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
