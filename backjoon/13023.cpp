#include <iostream>
#include <vector>

void DFS(int now, int depth);

// 인접 리스트 A 선언
static std::vector<std::vector<int>> A;

// 방문 여부 선언
static std::vector<bool> visited(8, false);

// 5번 도착 여부 선언
static bool isArrive = false;

int main() {
    // N : 노드, E : 엣지
    int N, E;
    std::cin >> N >> E;

    // A 초기화
    A.resize(N);

    for(int i = 0; i < E; i++) {
        int start, end;
        std::cin >> start >> end;
        // 양방향 방문 가능으로 모두 push_back
        A.at(start).push_back(end);
        A.at(end).push_back(start);
    }
    for(int i = 0; i < N; i++) {
        DFS(i, 1);
        if (isArrive) break;
    }

    if (isArrive)
        std::cout << 1 << std::endl;
    else
        std::cout << 0 << std::endl;

    return 0;
}

void DFS(int now, int depth) {
    // depth가 5이거나 이미 도착했을 경우 빠져나오기 위한 조건문
    if (depth == 5 || isArrive) {
        isArrive = true;
        return;
    }

    // 방문 여부 true로 변환
    visited.at(now) = true;

    for(int i : A.at(now)) {
        // 방문이 아직 안되었을 경우 재귀적으로 탐색
        if (!visited.at(i)) {
            DFS(i, depth + 1);
        }
    }

    // 방문 여부 false로 변환 - 다시 빠져나와서 탐색을 진행해야하므로
    visited.at(now) = false;
}