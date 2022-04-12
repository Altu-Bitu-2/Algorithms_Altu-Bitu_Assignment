//
// Created by ZERO-black 
// 튜터분이 작성하신 라이브 코드를 일부 수정했습니다. 
// 

#include <iostream>
#include <vector>

using namespace std;

// 필요한 동전 개수의 최솟값을 구하는 함수
int countCoin(int n, int k, vector<int> &coin) {
    // 이미 오름차순으로 정렬되어 있으므로 정렬 X
    int count = 0; // 사용된 총 동전 수 
    int idx = n - 1; // 큰 동전부터 계산해야 하므로 뒤에서부터 접근 
    while (k) {
        count += k / coin[idx]; // 해당 동전을 k를 만드는데 몇개 사용할 수 있는지 
        k %= coin[idx]; // 남은 돈 
        idx--;
    }
    return count;
}

int main() {
    int n, k;
    // 입력
    cin >> n >> k; // 동전 개수, 가치의 합 
    vector<int> coin(n, 0); // 각 동전의 가치 입력받기(오름차순으로 주어짐) 
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    // 연산 + 출력
    cout << countCoin(n, k, coin);
    return 0;
}
