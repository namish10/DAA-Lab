#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int source;
    cin >> source;

    const int INF = 1e9;
    vector<int> dist(V, INF);
    dist[source] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i < V; i++) {
        for (auto e : edges) {
            if (dist[e.u] != INF &&
                dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Check for negative-weight cycle
    for (auto e : edges) {
        if (dist[e.u] != INF &&
            dist[e.u] + e.w < dist[e.v]) {
            cout << "Negative weight cycle detected\n";
            return 0;
        }
    }

    // Print shortest distances
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << "Vertex " << i << ": Unreachable\n";
        else
            cout << "Vertex " << i << ": " << dist[i] << "\n";
    }

    return 0;
}