//
//  s_2.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 6. 30..
//  Copyright © 2017년 수노. All rights reserved.
//


#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
    int T, test_case;
   
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        
        Answer = 0;
        int n=0;
        int a[200001] = {0,};
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        
        int d[200001][3] = {0,};
        d[1][0] = 0;
        d[1][1] = a[1];
        d[1][2] = 0;
        
        for(int i=1; i<=n; i++){
            d[i][0] = max(max(d[i-1][0], d[i-1][1]), d[i-1][2]);
            d[i][1] = max(d[i-1][0], d[i-1][2]);
            d[i][2] = d[i][1];
        }
        
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }
    
    return 0;//Your program should return 0 on normal termination.
}
