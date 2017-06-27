//
//  10988.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 6. 27..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    cin >> input;
    bool check = true;
    
    if(input.size() != 1){
        for(int i=0; i<input.size()/2; i++){
            if(input[i] != input[input.size()-1-i]){
                check = false;
                break;
            }
        }
    }
    
    cout << check << "\n";
    return 0;
}
