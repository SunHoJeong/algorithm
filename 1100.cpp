//
//  1100.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 3. 7..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
    char graph[9][9];
    int ans=0;
    for(int i=0; i<8; i++){
        cin >> graph[i];
    }
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if((i+j)%2==0 && graph[i][j] == 'F')
                ans++;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
