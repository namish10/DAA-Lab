#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void prims(int V, vector<pair<int, int>> adj[]) {
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    vector<bool> visited(V, false);
    int totalWeight = 0;

    pq.push({0, 0});

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        totalWeight += weight;

        if (weight != 0)
            cout << "Vertex " << u << " - Weight " << weight << endl;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (!visited[v])
                pq.push({w, v});
        }
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            cout << "Graph is disconnected; MST does not exist.\n";
            return;
        }
    }

    cout << "Total weight of MST: " << totalWeight << endl;
}

int main() {
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<pair<int, int>> adj[V];

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    prims(V, adj);

    return 0;
}