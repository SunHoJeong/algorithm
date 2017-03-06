//
//  1032.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 7..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    string ans;
    int len = 0;
    cin >> n;
    
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        if(i==0){
            ans = str;
            len = (int)ans.size();
        }
        
        for(int j=0; j<ans.size(); j++){
            if(ans.at(j) != str.at(j)){
                ans[j] = '?';
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}
