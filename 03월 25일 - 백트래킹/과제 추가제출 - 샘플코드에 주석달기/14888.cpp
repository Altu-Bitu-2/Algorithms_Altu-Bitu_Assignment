#include <iostream>
#include <vector>

using namespace std;
const int INF_MAX = 1e9;
const int SIZE = 11;

int n;
vector<int> num(SIZE + 1);
vector<int> expression(4); //0: +, 1: -, 2: *, 3: /
int max_value = -INF_MAX, min_value = INF_MAX; // 최대, 최소범위로 초기화 

void backtracking(int cnt, int sum) { //cnt: 수 인덱스, sum: 연산 결과
    if (cnt == n - 1) { //연산 모두 완료했다면 (기저조건)
        max_value = max(max_value, sum); // 최댓값 업데이트 
        min_value = min(min_value, sum); // 최솟값 업데이트 
        return;
    }
    for (int i = 0; i < 4; i++) { //연산자 검사
        if (expression[i]) { 
            expression[i]--; // 해당 연산자 한번 사용 
            int new_sum = 0;
            switch (i) { //연산자 종류에 따라
            	// 전까지의 연산 값에 새로운 값 계산
                case 0: // +
                    new_sum = sum + num[cnt + 1];  
                    break;
                case 1: // - 
                    new_sum = sum - num[cnt + 1];
                    break;
                case 2: // *
                    new_sum = sum * num[cnt + 1];
                    break;
                case 3: // /
                    new_sum = sum / num[cnt + 1];
                    break;
            }
            backtracking(cnt + 1, new_sum);
            expression[i]++; 
        }
    }
}

/**
 * 연산자 모두 돌려보면서 배치한 후, 각 연산자에 따른 값 계산
 */

int main() {
    //입력
    cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> expression[i];
    }

    //연산
    backtracking(0, num[0]);

    //출력
    cout << max_value << '\n' << min_value;
    return 0;
}
