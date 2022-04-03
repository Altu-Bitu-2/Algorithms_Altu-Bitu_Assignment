#include <iostream> 
#include <cmath>

using namespace std;

// 마지막 데이터가 처리되는 컴퓨터의 번호를 찾아주는 함수
int findComNum(int a, int b, int cnt) {
	int a_pow = b % cnt; // a를 b번 곱했을 때(즉 마지막 데이터)의 일의 자리수 구하기

	// a의 일의 자리가 0일 때 예외
	if (a % 10 == 0) // 일의 자리가 0일 때는
		return 10; // 항상 10번째

	// b % cnt가 0이 될 때 예외
	if (cnt == 1) // cnt가 1일 때는 b번이 아무리 커도 모든 일의 자리가 a의 일의 자리와 같음. 즉 마지막 데이터의 일의 자리수는 항상 a % 10.
		return a % 10 % 10;
	if (b % cnt == 0) // b % 10가 0일 때는 패턴 중 가장 마지막 숫자여야 하는데 0이 되면 마지막 숫자를 가리키지 않으므로 예외처리
		a_pow += cnt; // 0이 된 a_pow에 패턴 횟수만큼을 더해서 패턴 중 마지막 숫자로 가도록 하기

	return (int)pow(a, a_pow) % 10;
}

// a의 일의 자리가 얼마마다 반복되는지 찾아주는 함수 
int findIterA(int a) {
	int temp = a % 10; // a 자체의 일의 자리 
	int cnt = 1; // 반복횟수 count
	while (true) {
		temp *= (a % 10); // a의 일의 자리 곱해주기
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