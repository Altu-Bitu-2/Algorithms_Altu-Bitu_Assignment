#include <iostream> 
#include <cmath>

using namespace std;

// 마지막 데이터가 처리되는 컴퓨터의 번호를 찾아주는 함수
int findComNum(int a, int b, int cnt) {
	if (a == 10) // a가 10일 때는
		return 10; // 항상 10번째
	if (cnt == 1) // cnt가 1일 때는 b번이 아무리 커도 모든 일의 자리가 a의 일의 자리와 같음. 즉 마지막 데이터의 일의 자리수는 항상 a % 10.
		return a % 10 % 10; 
	int a_pow = b % cnt; // a를 b번 곱했을 때(즉 마지막 데이터)의 일의 자리수 구하기
	return (int)pow(a, a_pow) % 10;
}

// a의 일의 자리가 얼마마다 반복되는지 찾아주는 함수 
int findIterA(int a) {
	int temp = a % 10; // a 자체의 일의 자리 
	int cnt = 1; // 반복횟수 count
	while (true) {
		temp *= a; // a 곱해주기
		temp %= 10; // 곱한 수의 일의 자리 구하기
		if (temp == a % 10) return cnt; // a 자체의 일의 자리로 돌아왔다면 반복횟수 return 
		cnt++; // 반복횟수 업데이트 
	}
}
int main() {
	int t;
	cin >> t; // 테스트케이스 개수 입력받기 

	int a, b;
	int cnt;
	for (int i = 0; i < t; i++) { // 테스트케이스 개수만큼 데이터 개수 입력받고 답 출력 
		cin >> a >> b;
		cnt = findIterA(a);
		cout << findComNum(a, b, cnt) << "\n";
	}

	return 0;
}