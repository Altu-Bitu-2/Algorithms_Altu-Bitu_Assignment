#include <iostream>
#include <vector>

using namespace std;

// 3*3 부분 행렬 원소 뒤집는 함수
void reverseMtx(int row, int col, vector<string> &matrix_a) {
    for (int i = row; i < row + 3; i++) { 
        for (int j = col; j < col + 3; j++) {
            if (matrix_a[i][j] == '1') { // 1이면 
                matrix_a[i][j] = '0'; // 0으로 바꾸기 
            } 
            else { // 0이면  
                matrix_a[i][j] = '1'; // 1로 바꾸기 
            }
        }
    }
}

//마지막으로 A == B인지 확인하는 함수
int isPossible(int n, int m, vector<string> &matrix_a, vector<string> &matrix_b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix_a[i][j] != matrix_b[i][j]) { // 같지 않은게 하나라도 생기면  
                return false; // false return 
            }
        }
    }
    return true; // 모두 같다면 true return 
}

/**
 * [행렬]
 *
 * (0, 0) 인덱스부터 부분행렬을 만들 수 있는 마지막 인덱스까지 검사하며 그리디하게 푸는 문제
 * A, B 행렬의 현재 인덱스 값이 서로 다르다면 A 행렬에서 현재 인덱스로 '시작'하는 3x3 크기만큼의 부분 행렬 원소 뒤집기
 * 검사가 모두 끝난 후, A와 B가 서로 다르다면 바꿀 수 없는 경우임
 * !주의! 입력이 공백없이 주어지므로 string으로 받음
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m; // 행렬 크기 
    vector<string> matrix_a(n); // 행렬 A
    vector<string> matrix_b(n); // 행렬 B 
	
	// 행렬 A 입력 
    for (int i = 0; i < n; i++) {
        cin >> matrix_a[i];
    }
	
	// 행렬 B 입력 
    for (int i = 0; i < n; i++) {
        cin >> matrix_b[i];
    }

    //연산
    int ans = 0;
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            if (matrix_a[i][j] != matrix_b[i][j]) { //(i, j)원소가 서로 다르다면
                reverseMtx(i, j, matrix_a); // a 원소 바꾸기 
                ans++; // ans 값 업데이트 
            }
        }
    }

    //출력
    if (!isPossible(n, m, matrix_a, matrix_b)) { // 같지 않다면 (바꿀 수 없다면)  
        ans = -1; // -1
    }
    cout << ans;
    return 0;
}
