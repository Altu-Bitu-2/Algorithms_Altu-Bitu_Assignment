#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * 각 줄마다 외계인이 누르고 있는 프렛을 스택에 저장하기
 * 매 입력에 대해 이번에 누를 프렛이 해당 줄에서 가장 높은 프렛이어야 함
 *
 * 1. 이번에 눌러야 할 프렛보다 높은 프렛에서 손가락을 전부 떼기
 * 2. 만약 이번에 눌러야 할 프렛을 누르고 있지 않다면 누르기
 *
 * 존재하지 않는 0번 프렛을 활용해서 스택에 미리 넣어줌으로써 매번 empty 체크를 해야 하는 연산을 줄임
 */
int main() {
    int n, p, guitar_string, fret, ans = 0;

    cin >> n >> p; //멜로디에 포함된 음의 개수와 프렛 수 입력받기 
    vector<stack<int>> guitar(7); //1번 줄부터 6번줄 까지. 각 줄마다 해당 줄의 눌러야할 프렛 목록이 스택으로 들어간다. 
    for (int i = 1; i <= 6; i++) { //스택에 미리 0을 넣어서 매번 empty 체크를 하는 연산을 줄임
        guitar[i].push(0);
    }
    while (n--) { //음의 개수만큼 while문 돌기 
        //입력
        cin >> guitar_string >> fret; //줄 번호와 프렛 번호 입력받기 

        //연산
        //프렛에서 손가락 떼기 
        //이번에 눌러야 할 프렛보다 높은 프렛이 눌려있을 경우 
        while (guitar[guitar_string].top() > fret) {
            ans++; //움직임 count 
            guitar[guitar_string].pop(); //떼기 
        }
        //프렛 누르기 
        //이번에 눌러야 할 프렛을 누르고 있지 않을 경우. 같은 줄의 다른 프렛을 누르고 있더라도 이번에 누를 프렛이 더 높을 때 누르는 경우도 포함 
        if (guitar[guitar_string].top() != fret) {
            ans++; //움직임 count 
            guitar[guitar_string].push(fret); //해당 줄의 프렛 stack에 넣어주기(누르고 있는 상태) 
        }

        //+이미 같은 줄에 같은 프렛이 눌려있다면 손가락 움직임이  필요없다. 
    }

    //출력
    cout << ans; //총 움직임 횟수 
}