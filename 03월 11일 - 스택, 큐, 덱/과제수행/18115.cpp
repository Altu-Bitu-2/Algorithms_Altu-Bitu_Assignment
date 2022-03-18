#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
 
using namespace std;

int main() { 
	int N;
	vector<int> A;
	
	cin >> N;
	
	//카드 기술 수열 입력받기
	for (int i=0;i<N;i++) {
		int card_tech;
		cin >> card_tech;
		A.push_back(card_tech);
	}
	
	//초기상태로 되돌아가는 것이므로 기술 거꾸로 수행 
	reverse(A.begin(),A.end());
	
	//초기상태의 카드를 저장할 deque
	deque<int> init;
	
	for (int i=0;i<N;i++) { 
		//1번 기술
		if (A[i]==1) init.push_front(i+1);
		//2번 기술
		if (A[i]==2) {
			int temp;
			temp = init.front(); //임시로 맨 앞 값 저장
			init.pop_front();
			init.push_front(i+1); //두번째에 넣어주기
			init.push_front(temp); //다시 첫번째 값 넣어주기 
		} 
		//3번 기술
		if (A[i]==3) init.push_back(i+1);
	}
	for (int i=0;i<N;i++) {
		cout << init[i] << " ";
	}
	
	return 0;
}