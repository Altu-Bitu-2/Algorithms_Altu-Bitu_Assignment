#include <iostream>
#include <tuple>

using namespace std;

// 총 타일의 개수(R+B)의 약수 쌍 구하기
// 이 약수 쌍 중 큰 것이 가로, 작은 것이 세로 
auto findDivisor(int r, int b) {
	// 약수 쌍 구하기  
	int sum = r + b; // 전체 타일 개수 
	int l, m; //약수 쌍, l > m 이라고 가정 
	int temp; // 특정 약수 쌍일 때의 빨간 타일 개수 
	for (int i = 3; i <= sum / 2; i++) { // 타일의 행이 3보다 작으면 B가 존재할 수 X. 따라서 i=3부터, 중복을 피하기 위해 sum/2 까지 
		if (sum % i == 0) { // 약수 
			m = i; // 세로 
			l = sum / i; // 가로 
			temp = l * 2 + (m - 2) * 2; // 해당 l, m 쌍일 때 빨간 타일의 개수 
				if (temp == r) return tuple(l, m); // 실제 빨간 타일의 개수와 동일하다면 이 약수 쌍이 실제 상근이네 방의 가로와 세로 길이 
		}
	}

	return tuple(0, 0); // 에러 방지용 코드 
}

int main() {
	// 입력
	int r, b;
	cin >> r >> b;

	auto [l, m] = findDivisor(r, b);
	cout << l << " " << m;

	return 0;
}
