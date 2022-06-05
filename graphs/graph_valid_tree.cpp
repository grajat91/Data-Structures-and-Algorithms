/*Description
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example

Example 1:
Input: n = 5 edges = [[0, 1], [0, 2], [0, 3], [1, 4]]
Output: true.*/

    bool validTree(int n, vector<vector<int>> &edges) {
        vector<int> adj[n];

        for (int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        queue<int> bfsq;
        vector<int> parent(n, -1);
        vector<bool> visited(n, false);
        bfsq.push(0);
        visited[0] = true;
        while (!bfsq.empty()) {
            int u = bfsq.front();
            bfsq.pop();
            for (auto v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    bfsq.push(v);
                    parent[v] = u;
                } else if (parent[u] != v) return false;
            }
        }
        for (int i=0;i<n;i++) {
            if (!visited[i]) return false;
        }
        return true;
    }
