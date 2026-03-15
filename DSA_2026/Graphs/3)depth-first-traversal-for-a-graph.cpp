#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfsHelper(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans){
        vis[node] = 1;
        ans.push_back(node);

        for(auto it : adj[node]){
            if(!vis[it]){
                dfsHelper(it, adj, vis, ans);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {

        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> ans;

        dfsHelper(0, adj, vis, ans);

        return ans;
    }
};

int main(){
    
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);

    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // remove this line if graph is directed
    }

    Solution obj;
    vector<int> result = obj.dfs(adj);

    cout << "DFS Traversal: ";
    for(auto x : result){
        cout << x << " ";
    }

    return 0;
}

//bbasically wohi jo provide krte hein vector jisme connecctions hote hien ki adj.. like adjencry list basically.. woh de rkhi he function me we have to implement dfs which is depth first search.. depth matlb jo bhi neighbor pakda .. like first neigbhor uske unvisited's ko visits krna he sbse pehle.. now the thing is adj ki size leke usse woh all false waali vector bana lenge.. and ek apna ans vector bana lenge.. ek dfs helper function banynge.. named dfshelper usme ye sb bhejenge.. we are starting from zero so 0 fir adj list jo provided he in the main functtion and vis vector jisme false false hota he in the start.. and ans vector.. in that function we are just falase ko true kr rhe for whatever comes so zero aaya tha toh waha pe true krdiya now ek for loop for zero ke neighborss jisme we are checking jaha bhi no he waha pe apan recursion kr reh jisme apan wohi neigbor firse bhejenge
//dry run krke dekh liyo.. for it. https://youtu.be/3czYbhac160?si=AhRz_c_Qt73sRV5E



//Basically the adjacency list is already provided in the adj vector, where all the connections (neighbors of each node) are stored. We just have to implement DFS (Depth First Search). Depth means whenever we pick a neighbor, we first visit all of its unvisited neighbors completely before moving to the next neighbor.

// First we take the size of adj and create a visited vector of that size where initially all values are false. We also create an answer vector where we will store the DFS traversal.

// Then we create a dfsHelper function. In that function we pass the current node, adjacency list, visited vector, and answer vector. We start DFS from node 0, so we call the helper with 0.

// Inside the helper function, whatever node comes we mark it visited (false → true) and push it into the answer vector.

// After that we run a for loop on the neighbors of that node using the adjacency list. If any neighbor is not visited, we simply call the recursive DFS function again with that neighbor. This way DFS goes deeper first and keeps visiting nodes until no unvisited neighbors are left.

// Time Complexity

// O(V + E) because each vertex and each edge of the graph is visited at most once.

// Space Complexity

// O(V) because we use a visited vector of size V and the recursion stack in the worst case can also go up to V.