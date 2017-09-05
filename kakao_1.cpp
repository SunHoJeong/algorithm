//
//  kakao_1.cpp
//  Algorithm_2017
//
//  Created by 수노 on 2017. 8. 5..
//  Copyright © 2017년 수노. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> P;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer(2);
    
    int dir[4][2] = {{1,0}, {0,1}, {-1,0},{0,-1}};
    bool visited[101][101] = {false,};
    queue<P> q;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && picture[i][j] != 0){
                int num = picture[i][j];
                q.push(P(i,j));
                visited[i][j] = true;
                number_of_area += 1;
                cout << "plus:" << num<<"\n";
                cout << i<<","<<j<<"\n";
                int cnt = 1;
                
                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    
                    for(int k=0; k<4; k++){
                        int rr = r +dir[k][0];
                        int cc = c +dir[k][1];
                        
                        if(0 > rr || rr >= m || 0 > cc || cc >= n)
                            continue;
                        
                        if(!visited[rr][cc] && picture[rr][cc] == num){
                            q.push(P(rr,cc));
                            visited[rr][cc] = true;
                            cnt += 1;
                        }
                    }
                }
                
                if(max_size_of_one_area < cnt){
                    max_size_of_one_area = cnt;
                }
            }
        }
    }
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main(){
    vector<int> result = solution(6, 4, {{1, 1, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}});
    
    cout << result[0] << "," << result[1] << "\n";
    return 0;
}
