#include <iostream>
using namespace std;

const int MAX = 100;

int findMinVertex(int key[], bool mstSet[], int V) {
    int min = 9999, minIndex;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primsAlgorithm(int graph[MAX][MAX], int V) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = 9999;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinVertex(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int graph[MAX][MAX];
    cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    primsAlgorithm(graph, V);

    return 0;
}
