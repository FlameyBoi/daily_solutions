using namespace std;

#include <vector>

class Graph {
    int** min_path;
    int nodes;
    const int no_val = INT_MAX / 4;
public:
    Graph(int n, vector<vector<int>>& edges) {
        min_path = new int* [n];
        nodes = n;
        for (int i = 0; i < n; i++)
        {
            min_path[i] = new int[n];
            for (int j = 0; j < n; j++)
                min_path[i][j] = no_val;
            min_path[i][i] = 0;
        }

        for (int i = 0; i < edges.size(); i++)
            min_path[edges[i][0]][edges[i][1]] = edges[i][2];

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                {
                    if (min_path[i][j] > min_path[i][k] + min_path[k][j])
                    {
                        min_path[i][j] = min_path[i][k] + min_path[k][j];
                    }
                }
    }

    ~Graph()
    {
        for (int i = 0; i < nodes; i++)
        {
            delete[] min_path[i];
        }
        delete[] min_path;
    }

    void addEdge(vector<int> edge) {
        int node1 = edge[0], node2 = edge[1], weight = edge[2];
        if (min_path[node1][node2] > weight)
            for (int i = 0; i < nodes; i++)
                for (int j = 0; j < nodes; j++)
                {
                    if (min_path[i][j] > min_path[i][node1] + weight + min_path[node2][j])
                        min_path[i][j] = min_path[i][node1] + weight + min_path[node2][j];
                }

    }

    int shortestPath(int node1, int node2) {
        return (min_path[node1][node2] == no_val) ? -1 : min_path[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */