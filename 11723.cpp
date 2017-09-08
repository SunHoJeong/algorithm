//
//  11723.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 9. 8..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <cstdio>
#include <cstring>

using namespace std;

char cmd[111];

int main(){
    int n;
    scanf("%d", &n);
    int s = 0;
    
    for(int i=0; i<n; i++){
        int num = 0;;
        
        scanf("%s", cmd);
        
        if(!strcmp(cmd, "add")){
            scanf("%d", &num);
            num --;
            
            s = (s | (1 << num));
        }
        else if(!strcmp(cmd, "remove")){
            scanf("%d", &num);
            num --;
            
            s = (s & ~(1 << num));
        }
        else if(!strcmp(cmd, "check")){
            scanf("%d", &num);
            num --;
            
            int save = (s & (1<<num));
            if(save){
                printf("%d\n", 1);
            }
            else{
                printf("%d\n", 0);
            }
        }
        else if(!strcmp(cmd, "toggle")){
            scanf("%d", &num);
            num --;
            
            s = (s ^ (1 << num));
        }
        else if(!strcmp(cmd, "all")){
            s = (1 << n) -1;
        }
        else if(!strcmp(cmd, "empty")){
            s = 0;
        }
    }
    
    return 0;
}
