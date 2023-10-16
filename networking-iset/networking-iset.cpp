#include <stdio.h>
#include <vector>
#include <queue>
#include <climits>
#include <iostream>



int findDiameter(std::vector<std::vector<std::pair<int,int>>>& graph, int n, std::pair<int, int> start) {
    std::queue<int> q;
    std::vector<bool> visited(n + 1, false);
    int dist = 0;

    q.push(start.first);
    visited[start.first] = true;
    if (start.second != -1) {
        q.push(start.second);
        visited[start.second] = true;
    }

    int diameter_half_1 = -1, diameter_half_2 = -1;
    while (!q.empty()) {
        int level = q.size();
        for (int i = 0; i < level; i++) {
            int v = q.front();
            q.pop();
            bool isLeaf = true;
            for (auto& [u, edge] : graph[v]) {
                if (!visited[u]) {
                    q.push(u);
                    visited[u] = true;
                    isLeaf = false;
                }
            }
            if (isLeaf) {
                if (diameter_half_1 == -1 || dist > diameter_half_1) {
                    diameter_half_1 = dist;
                }
                if (diameter_half_2 == -1 || diameter_half_1 > diameter_half_2) {
                    std::swap(diameter_half_1, diameter_half_2);
                }
            }
        }
        dist++;
    }
    int diameter = diameter_half_1 + diameter_half_2;
    if (start.second == -1) diameter--;
    return diameter;
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<std::vector<std::pair<int, int> > > graph(n + 1);
    std::vector<std::pair<int, int> > edges;

    for (int i = 0; i < m; ++i) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        graph[v1].emplace_back(v2, i);
        graph[v2].emplace_back(v1, i);
        edges.emplace_back(v1, v2);
    }

    std::pair<int, int> center = std::make_pair(1, -1);
    int diameter = INT_MAX;

    for (int i = 1; i <= n; ++i) {
        int curDiameter = findDiameter(graph, n, std::make_pair(i, -1));
        if (curDiameter < diameter) {
            diameter = curDiameter;
            center.first = i;
        }
    }

    for (std::pair<int, int>& edge : edges) {
        int curDiameter = findDiameter(graph, n, edge);
        if (curDiameter < diameter) {
            diameter = curDiameter;
            center = edge;
        }
    }

    std::queue<int> q;
    std::vector<bool> visited(n + 1, false);
    q.push(center.first);
    visited[center.first] = true;
    if (center.second != -1) {
        q.push(center.second);
        visited[center.second] = true;
        printf("%d %d\n", center.first, center.second);
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& [u, edge] : graph[v]) {
            if (!visited[u]) {
               q.push(u);
               printf("%d %d\n", edges[edge].first, edges[edge].second);
               visited[u] = true;
            }
        }
    }
}
