//
// Created by BaeSuA on 2022-03-29.
// 튜터분이 작성하신 라이브 코드를 일부 수정했습니다. 
//

#include <iostream>
#include <vector>

using namespace std;

// 물품에 대한 무게와 가치 구조체 
struct info {
    int w, v;
};

int knapsack1(int n, int k, vector<info> &product) {
    vector<int> dp(k + 1, 0);

    for (int i = 1; i <= n; i++) { //i: 물품
        for (int j = k; j >= product[i].w; j--) { //j: 최대 배낭 무게
            //i번째 물품을 배낭에 넣은 경우와 안 넣은 경우 중 최댓값 저장
            dp[j] = max(dp[j - product[i].w] + product[i].v, dp[j]);
        }
    }
    return dp[k];
}

int knapsack2(int n, int k, vector<info> &product) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0)); // 현재 물건과, 그에 해당하는 0~최대무게까지의 가치 저장 

    for (int i = 1; i <= n; i++) { //i: 현재 넣으려는 물품
        //j: 현재 최대 배낭 무게
        // 굳이 점화식이 필요없는 부분.  
        for (int j = 0; j < product[i].w; j++) { //어차피 최대 배낭 무게가 물품 무게보다 작아서 물품을 배낭에 못넣음
            dp[i][j] = dp[i - 1][j]; //그 전의 값 그대로 사용
        }
        // 현재 가방 무게가 해당 물품을 넣을 수 있을만큼 충분히 크다면 최대 가치 업데이트 확인 
        for (int j = product[i].w; j <= k; j++) { // 최대무게까지 
            //배낭에 넣은 경우와 안 넣은 경우 중 최댓값 저장
            dp[i][j] = max(dp[i - 1][j - product[i].w] + product[i].v, dp[i - 1][j]);
        }
    }
    return dp[n][k];
}

int main() {
    int n, k; 

    //입력
    cin >> n >> k; // 물품의 개수와 가방에 넣을 수 있는 최대 무게 
    vector<info> product(n + 1, {0, 0}); // 물품 구조체 초기화 
    for (int i = 1; i <= n; i++) { // dp에서 i-1에 접근하기 때문에 0번 인덱스는 비워두고 1번 인덱스부터 방문 
        cin >> product[i].w >> product[i].v; // 각 물품의 무게와 가치 입력받기 
    }

    //연산 & 출력
    cout << knapsack1(n, k, product);
    return 0;
}
