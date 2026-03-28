#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int node, vector<int> adj[], vector<bool> &vis, stack<int> &st) {
        vis[node] = true;

        for (int v : adj[node]) {
            if (!vis[v]) {
                dfs(v, adj, vis, st);
            }
        }

        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];

        // build graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        vector<bool> vis(V, false);
        stack<int> st;

        // call dfs for all components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        vector<int> topo;

        // get topo order
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }

        return topo;
    }
};

int main() {
    int V = 6;

    // edges: u -> v
    vector<vector<int>> edges = {
        {5, 2},
        {5, 0},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };

    Solution obj;
    vector<int> result = obj.topoSort(V, edges);

    cout << "Topological Sort: ";
    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}


// Topological sort ka core intuition simple hai: hume ek aisa order chahiye jahan agar u → v hai, toh u hamesha v se pehle aaye, kyunki v dependent hai u pe. DFS yaha help karta hai because wo naturally graph ke end tak (last dependency tak) chala jaata hai. Jab hum DFS me kisi node ke saare neighbours (dependencies) explore kar lete hain, tabhi us node ko stack me push karte hain—matlab hum ensure kar rahe hain ki uske baad wale sab nodes pehle handle ho chuke hain. Isse stack me nodes reverse order me store hote hain (last wale pehle), aur jab hum stack ko pop karte hain, toh automatically correct topological order mil jaata hai jahan har u apne v se pehle aata hai.