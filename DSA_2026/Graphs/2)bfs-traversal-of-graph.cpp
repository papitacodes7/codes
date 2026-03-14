#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> bfs(vector<vector<int>> &adj) {
        
        vector<int> ans;
        int n = adj.size();

        vector<bool> vis(n,false);
        queue<int> q;

        q.push(0);
        vis[0] = true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int neighbour : adj[node])
            {
                if(!vis[neighbour])
                {
                    vis[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        return ans;
    }
};

int main()
{
    int n = 5;
    vector<vector<int>> adj(n);

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(4);
    adj[4].push_back(2);

    Solution obj;
    vector<int> res = obj.bfs(adj);

    for(int x : res)
    {
        cout << x << " ";
    }

    return 0;
}

//so basically we made q first then vector of false values with 0 we pushed 0 in q and marked true and then in a while loop until q ends we we took starting node from q.front fir we q.pop then we pushed it into and vec now for neighbour check we used a for each loop inside the while loop like ( int neighbour : adj[node] ) and inside it we just have to check if whatever the neigbhorss were visited or not.. if visited we do nothing if not visited we assign to true and and push into queue. endif endfor end while and we return ans.

//Basically first we create a queue and a visited array. The visited array is initialized with false values because initially no node has been visited. Then we start the traversal from node 0, so we push 0 into the queue and mark vis[0] = true. After that we run a while loop until the queue becomes empty. Inside the loop we take the node at the front of the queue using q.front() and then remove it using q.pop(). This node becomes the current node and we push it into our answer vector ans. After that we check all the neighbours of this node using a for-each loop for(int neighbour : adj[node]). For every neighbour we check whether it has been visited or not using if(!vis[neighbour]). If it is already visited we do nothing, but if it is not visited we mark it as visited and push it into the queue so that it can be processed later. This process keeps repeating until the queue becomes empty, which means all the nodes reachable from the starting node have been explored. Finally we return the answer vector ans which contains the BFS traversal order. The time complexity of this algorithm is O(V + E) because each vertex is visited once and every edge is checked once during traversal, where V is the number of vertices and E is the number of edges in the graph. The space complexity is O(V) because we use a visited array, a queue, and an answer vector which all store at most V elements.