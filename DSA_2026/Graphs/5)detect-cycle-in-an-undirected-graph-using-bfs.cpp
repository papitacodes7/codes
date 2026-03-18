#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isCycleBFS(int src, vector<int> adj[], vector<bool> &vis) {
        queue<pair<int,int>> q;
        
        q.push({src, -1});
        vis[src] = true;
        
        while (!q.empty()) {
            int u = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (int v : adj[u]) {
                if (!vis[v]) {
                    q.push({v, u});
                    vis[v] = true;
                } 
                else if (v != parent) {
                    return true; // cycle found
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (isCycleBFS(i, adj, vis))
                    return true;
            }
        }
        
        return false;
    }
};

int main() {
    int V = 5;
    
    // Example edges (undirected)
    vector<vector<int>> edges = {
        {0,1}, {1,2}, {2,3}, {3,4}, {4,1} // cycle present
    };

    Solution obj;
    
    if (obj.isCycle(V, edges)) {
        cout << "Cycle detected\n";
    } else {
        cout << "No cycle\n";
    }

    return 0;
}


//bfs me hum queue use karte hain jisme hum {node, parent} store karte hain kyunki hume pata hona chahiye ki hum kis node se aaye hain. sabse pehle hum src node ko {src, -1} ke saath push karte hain aur usko visited mark kar dete hain. phir jab tak queue empty nahi hota tab tak hum front se ek node u aur uska parent nikalte hain. ab hum uske saare neighbours pe iterate karte hain using for (int v : adj[u]). agar koi neighbour visited nahi hai to usko mark karke {v, u} ke saath queue me push kar dete hain. lekin agar koi neighbour already visited hai aur wo parent ke equal nahi hai to iska matlab hum kisi aur path se wapas us node tak pahunch gaye hain, jo ki cycle ka indication hai, to hum true return kar dete hain. agar poora traversal ho gaya aur aisa case nahi mila to graph me cycle nahi hai. TC: O(V + E), SC: O(V + E)

//https://youtu.be/MIjOkApZ39g?si=pn-CWdLPYqfYR7xB watch it