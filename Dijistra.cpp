#include <iostream>
using namespace std;

int main()
{
    int strt;
    int mindist;
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;
    int adj[v][v];
    int visited[v];
    int distance[v];
    int totaldist = 0;

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << "Enter the cost from " << i << " to " << j << " :";
            cin >> adj[i][j];
            if (i != j && adj[i][j] == 0)
            {
                adj[i][j] = 999; // Represent no connection as "infinity"
            }
        }
    }

    cout << "Entered Adjacency Matrix is as follows: " << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter the starting vertex: ";
    cin >> strt;

    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;     // Mark all vertices as unvisited
        distance[i] = 999;  // Set initial distances to infinity
    }
    distance[strt] = 0; // Distance to the starting vertex is 0

    for (int count = 0; count < v - 1; count++)
    {
        mindist = 999;
        int nextnode = -1;

        // Find the unvisited node with the smallest distance
        for (int i = 0; i < v; i++)
        {
            if (!visited[i] && distance[i] < mindist)
            {
                mindist = distance[i];
                nextnode = i;
            }
        }

        if (nextnode == -1)
            break; // If no next node is found, break (disconnected graph)

        visited[nextnode] = 1;

        // Update distances of adjacent nodes
        for (int i = 0; i < v; i++)
        {
            if (!visited[i] && adj[nextnode][i] != 999 &&
                distance[nextnode] + adj[nextnode][i] < distance[i])
            {
                distance[i] = distance[nextnode] + adj[nextnode][i];
            }
        }

        cout << "Iteration " << count + 1 << ":\n";
        cout << "Visited: ";
        for (int i = 0; i < v; i++)
        {
            cout << visited[i] << " ";
        }
        cout << "\nDistance: ";
        for (int i = 0; i < v; i++)
        {
            cout << distance[i] << " ";
        }
        cout << "\n-------------------------------------------------------" << endl;
    }

    cout << "Shortest distances from vertex " << strt << ":\n";
    for (int i = 0; i < v; i++)
    {
        cout << "To vertex " << i << ": " << distance[i] << endl;
    }

    return 0;
}