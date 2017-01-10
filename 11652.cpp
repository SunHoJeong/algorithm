#include <cstdio>
#include <algorithm>

using namespace std;

long long arr[1000001];


int main(){
    int n;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%lld", &arr[i]);
    }
    
    sort(arr, arr+n);
    
    long long ans = 0;
    int ans_cnt = 0;
    int temp_cnt = 1;
    
    for(int i=1; i<n; i++){
        if(arr[i] == arr[i-1]){
            temp_cnt ++;
        }
        else if(arr[i] != arr[i-1]){
            temp_cnt = 1;
        }
        
        if(ans_cnt < temp_cnt){
            ans_cnt = temp_cnt;
            ans = arr[i];
        }
    }
    
    printf("%lld\n",ans);
    return 0;
}
