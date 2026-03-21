#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool dfs(int curr, vector<int> adj[], vector<bool> &vis, vector<bool> &recPath) {
        vis[curr] = true;
        recPath[curr] = true;
        
        for (int v : adj[curr]) {
            if (!vis[v]) {
                if (dfs(v, adj, vis, recPath))
                    return true;
            }
            else if (recPath[v]) {
                return true;
            }
        }
        
        recPath[curr] = false; // backtrack
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> adj[V];
        
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v); // directed graph
        }
        
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, recPath))
                    return true;
            }
        }
        
        return false;
    }
};

int main() {
    Solution obj;

    int V = 4;

    // Example: 0 → 1 → 2 → 3 → 1 (cycle)
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 1}
    };

    if (obj.isCyclic(V, edges))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    return 0;
}

// In a **directed graph**, we use **DFS** to explore nodes along a path, and a cycle is detected when DFS reaches a node that is already part of the **current recursion path**. Since direction matters, the concept of a “parent” is not reliable, so instead we track two things: `vis` to mark nodes we have already visited during DFS (to avoid reprocessing), and `recPath` to mark nodes that are currently in the active DFS call stack. If during DFS we encounter a node that is already marked in `recPath`, it means we have returned to a node in the same path, forming a cycle. This distinction is important because a node can be visited earlier (via another path) without forming a cycle, but being in the current DFS path specifically indicates a loop.
//https://youtu.be/AcppN5XFt24?si=DvsjLfENbupfJRU0 dekh liyo ek baar
// edit on 22/3/26 kuch nhi kiya cz of assignments.. 