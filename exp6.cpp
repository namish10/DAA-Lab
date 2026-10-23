#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;

void dijkstra(int source, int V, vector<pair<int, int>> adj[]) {
    vector<int> dist(V, INF);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d != dist[u])
            continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest distances from source " << source << ":\n";

    for (int i = 0; i < V; i++) {
        cout << source << " -> " << i << " = ";

        if (dist[i] == INF)
            cout << "Unreachable";
        else
            cout << dist[i];

        cout << endl;
    }
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
        adj[v].push_back({u, w});  // Undirected graph
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    dijkstra(source, V, adj);

    return 0;
}