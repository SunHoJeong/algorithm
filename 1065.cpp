//
//  1065.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 2. 27..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int ans = 0;
    
    for(int i=1; i<=n; i++){
        if(i < 100)
            ans += 1;
        else if(i==1000){
            
        }
        else{
            string str = to_string(i);
            int len = (int)str.size();
            //cout << str[1]-str[0] <<"," << str[2]-str[1] << "\n";
            if(str[1]-str[0] == str[2]-str[1]){
                ans += 1;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
