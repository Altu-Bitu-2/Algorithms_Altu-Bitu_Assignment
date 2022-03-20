#include <iostream>
#include <queue>

using namespace std;
queue<int> q;

int main() {
	int n,k;
	cin >> n >> k;

	//1~n번 숫자 넣기 
	for(int i=1;i<=n;i++){
		q.push(i);
	}

	cout << "<";

	while(!q.empty()) {
		//k번째 전까지의 숫자는 큐의 뒤에 push 해주고 pop하기 
		for (int i=1;i<k;i++){
		q.push(q.front());
		q.pop();
		}

		//k번째 숫자 출력 
		cout <<q.front();
		q.pop(); //출력 후 pop 해주기 
		if(!q.empty()) cout << ", "; //, 출력. 단, 마지막에는 출력 안되게 if문 
	}

	cout << ">";

	return 0;
}