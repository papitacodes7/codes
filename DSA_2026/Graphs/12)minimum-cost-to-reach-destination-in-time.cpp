// class Solution {
// public:
//     int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        
//     }
// };

// tomorrow do from https://youtu.be/8gYBHjtjWBI?si=QWsLBBU6E9MQERgX 11:20
// today is 6:45 the continuation is here..

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // Step 1: Adjacency List
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // remove if directed
        }
        
        // Step 2: Distance Array
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        // Step 3: Min Heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        
        // Step 4: Dijkstra
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            
            if(d > dist[node]) continue;
            
            for(auto &it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                
                if(d + wt < dist[adjNode]){
                    dist[adjNode] = d + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    
    vector<vector<int>> edges;
    
    // Input edges: u v w
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    
    int src;
    cin >> src;
    
    Solution obj;
    vector<int> result = obj.dijkstra(V, edges, src);
    
    // Output distances
    for(int i = 0; i < V; i++){
        if(result[i] == INT_MAX) cout << "INF ";
        else cout << result[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}

//Dijkstra algorithm ko hum sirf positive weighted graphs ke liye use karte hain kyuki yeh ek greedy approach follow karta hai jahan hum hamesha us node ko pick karte hain jo source ke sabse paas (minimum distance) hai using a min-heap (priority queue). Graph ko hum adjacency list me store karte hain aur ek dist[] array banate hain jisme initially sab values ∞ hoti hain except source jiska distance 0 hota hai. Phir hum pq me {distance, node} daalte hain aur jab bhi koi node pop hota hai, uske saare neighbours ke liye edge relaxation apply karte hain, yani check karte hain ki current path (dist[u] + weight) purane stored distance se chhota hai ya nahi; agar haan, toh update karke pq me push kar dete hain. Is process me distances gradually improve hote rehte hain (jaise tumne bola: 4 se 3 ho jaana), jab tak sab shortest paths mil na jaayein. Time Complexity hoti hai O((V + E) log V) (ya approx O(E log V)) kyuki har edge relaxation ke time priority queue operations lagte hain, aur Space Complexity hoti hai O(V + E) adjacency list aur dist array ke liye.