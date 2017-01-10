//
//  11655.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 1. 4..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(){
    string str;
    string result;
    
    getline(cin, str);
    
    for(int i=0; i<str.size(); i++){
        if(str[i] == ' '){
            cout << str[i];
        }
        else if(65<=str[i] && str[i] <=122){
            if(65 <= str[i] && str[i] <= 90){
                int temp = str[i] +13;
                if(temp > 90){
                    temp = temp -26;
                }
                cout << (char)temp;
            }
            else if(97 <= str[i] && str[i] <=122){
                int temp = str[i] +13;
                if(temp > 122){
                    temp = temp-26;
                }
                cout << (char)temp;
            }
        }
        else{
            cout << str[i];
        }
    }
    
    cout << '\n';
    
}
