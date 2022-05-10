#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5 * 8 * 3; //최대 N-1개의 간선을 지나게 됨 * 중복 순회 가능(3)

//다익스트라
vector<int> dijkstra(int start, int v, vector<vector<ci>> &graph) {
    vector<int> dist(v + 1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
    	// 미리 가중치와 노드 저장 
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop(); // 다음을 위해 pop 

        if (weight > dist[node]) { // 최소가 아니라면 (값이 더 크다면)  
            continue; // 갱신 X  
        }
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first; // 연결된 다음노드  
            int next_weight = weight + graph[node][i].second; // 다음 노드까지의 거리 
            if (next_weight < dist[next_node]) { // 새로운 값이 더 작다면 
                dist[next_node] = next_weight; // 갱신 
                pq.push({next_weight, next_node}); // pq에 넣저구  
            }
        }
    }
    return dist;
}

/**
 * [특정한 최단 경로]
 *
 * 가능한 경로
 * 1. 1 -> v1 -> v2 -> n
 * 2. 1 -> v2 -> v1 -> n
 * -> 1, v1, v2를 시작점으로 하는 다익스트라 함수 실행하기
 *
 * !주의! 한 번 이동했던 정점, 간선을 다시 방문할 수 있음. 즉 1->N의 최댓값이 INF(1e5*8)이 아니라 3*INF!
 */

int main() {
    int n, e, a, b, c, v1, v2;

    //입력
    cin >> n >> e; // 정점 개수와 간선 개수 

    vector<vector<ci>> graph(n + 1, vector<ci>(0));
    vector<vector<int>> dist(3, vector<int>(n + 1, 0));
    while (e--) { //무방향 그래프
        cin >> a >> b >> c; // 연결된 정점과 거리 
        graph[a].emplace_back(b, c); // a에 b 연결, 거리 
        graph[b].emplace_back(a, c); // b에 a 연결, 거리 
    }
    cin >> v1 >> v2; // 반드시 거쳐야 하는 정점 2개 

    //연산
    vector<int> start_nodes = {1, v1, v2};
    for (int i = 0; i < 3; i++) { //1, v1, v2에서 시작한 다익스트라 결과 저장
        dist[i] = dijkstra(start_nodes[i], n, graph);
    }

    //1->v1->v2->n의 경로와 1->v2->v1->n의 경로 중 최솟값
    //무방향 그래프기 때문에 v1->v2와 v2->v1은 사실 같은 값!
    int ans = min(dist[0][v1] + dist[1][v2] + dist[2][n], dist[0][v2] + dist[2][v1] + dist[1][n]);

    //출력
    cout << ((ans >= INF) ? -1 : ans); // ans가 INF이상이면 경로X/ -1 출력 
    return 0;
}
