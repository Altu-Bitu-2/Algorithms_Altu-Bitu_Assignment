#include <iostream>
#include <vector>

using namespace std;

int chooseSushi(int n, int d, int k, int c, vector<int> &belt) {
    vector<int> sushi(d + 1, 0); //초밥 종류별  먹은 개수

    //쿠폰으로 먹은 초밥
    int section_sushi = 1;
    sushi[c]++; // 쿠폰 번호 초밥 먹음 

    //윈도우 초기화
    for (int i = 0; i < k; i++) {
        if (!sushi[belt[i]]) { // 이미 먹은 초밥 아니면 
            section_sushi++; // 먹은 개수 업데이트 
        }
        sushi[belt[i]]++; // 먹은 초밥 업데이트 
    }

    int ans = section_sushi;
    for (int i = k; i < n + k; i++) { //슬라이딩 윈도우
        sushi[belt[i - k]]--; // 전의 값 없애기  
        if (!sushi[belt[i - k]]) { // 전의 값 
            section_sushi--; // 업데이트 
        }
        if (!sushi[belt[i % n]]) { // 새로운 접시 추가 
            section_sushi++; // 업데이트 
        }
        sushi[belt[i % n]]++; // 먹었다고 업데이트 
        ans = max(ans, section_sushi);
    }
    return ans;
}

/**
 * [회전 초밥]
 *
 * 1. 연속해서 먹어야 할 접시가 k로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * 3. 쿠폰으로 먹은 초밥을 먼저 고려해놓기
 * 4. 초밥의 종류가 최대 3000개로 많지 않음. 각 종류별 먹은 초밥의 개수를 세어주기
 */

int main() {
    int n, d, k, c;

    //입력
    cin >> n >> d >> k >> c; // 접시의 수, 초밥 가짓수, 연속해서 먹는 접시의 수, 쿠폰 번호 
    vector<int> belt(n, 0); // 접시에 놓인 초밥 종류 
    for (int i = 0; i < n; i++) {
        cin >> belt[i]; // 접시에 초밥 종류 입력하기 
    }

    //연산 & 출력
    cout << chooseSushi(n, d, k, c, belt);
    return 0;
}
