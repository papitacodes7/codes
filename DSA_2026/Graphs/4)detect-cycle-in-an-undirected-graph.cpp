// cycle ki condition undirected graph me dfs krte hue tb ture hoti he jab hume ek back edge milta he.. back edge is basically kisi vertice ke neighbour jo visited toh he par uska parent nhi (immidiate parent wala node) he.. that means uss verice pe pochnee ke two ways he.. iska matlab a cycle exists.. https://youtu.be/OZClCpPQDR4?si=9ay4JcbDQnKXQ5fw 10:55..
//watch video..fr

//We start from any node, mark it visited, and then explore all its neighbours using DFS; if a neighbour is not visited, we recursively go deeper while passing the current node as its parent, but if we find a neighbour that is already visited and is not the parent of the current node, it means we have reached a node through a different path, so a cycle exists; we repeat this process for all components of the graph to ensure no cycle is missed. The time complexity is O(V + E) and space complexity is O(V) due to the visited array and recursion stack.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        
        for (auto neighbour : adj[node]) {
            if (!vis[neighbour]) {
                if (dfs(neighbour, node, adj, vis))
                    return true;
            }
            else if (neighbour != parent) {
                return true;
            }
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        // adjacency list (clean version)
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> vis(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis))
                    return true;
            }
        }
        
        return false;
    }
};

int main() {
    int V = 5;
    
    // Example graph (cycle present)
    vector<vector<int>> edges = {
        {0,1}, {1,2}, {2,0}, {0,3}, {3,4}
    };
    
    Solution obj;
    
    if (obj.isCycle(V, edges))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";
        
    return 0;
}