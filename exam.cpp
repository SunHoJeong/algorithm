#include <iostream>
#include <vector>

using namespace std;

int n,s;
int ans = 0;
void dfs(vector<int>& v, int index, int sum){
    //cout << index << "," << sum << "\n";
    if(index >= n){
        if(sum == s){
            ans += 1;
        }
        return;
    }
    
    dfs(v,index+1, sum+v[index]);
    dfs(v,index+1, sum);
}

int main(){
    cin >> n >> s;
    
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    dfs(v,0,0);
    
    if(s == 0)
        ans--;
    
    cout << ans << "\n";
    
    return 0;
}
