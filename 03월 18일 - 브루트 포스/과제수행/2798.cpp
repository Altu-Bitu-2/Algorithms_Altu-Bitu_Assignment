#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// 입력
	int n, m;
	cin >> n >> m;
	vector<int> card(n);
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	// 3장을 뽑는 모든 경우 구하기 
	vector<int> sum;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				sum.push_back(card[i] + card[j] + card[k]);
			}
		}
	}

	// M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합 출력하기 
	sort(sum.begin(), sum.end(), greater<>()); // 내림차순 정렬 
	for (int i = 0; i < sum.size(); i++) {
		if (sum[i] > m) continue; // M보다 큰 경우는 제외 
		cout << sum[i]; // M보다 큰 수 제외하고 가장 맨 앞의 수기  최댓값 
		break; // 최댓값 출력했으면 반복문 빠져나오기 
	}

	return 0;
}