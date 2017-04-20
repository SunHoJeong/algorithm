//
//  skct.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 4. 19..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>

int main(){
    
    int a=0,b=0,c=0,d=0;
    
    for(;a<10;a++){
        b++;
        ++c;
        d = b+c;
        if(d>11)
            break;
        
    }
    printf("a = %d\n",a);
    return 0;
}
