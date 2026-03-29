// cycle hogi toh according to question ki second value pehle visit krni he first waali se would fail so cycle nhi honi chahiye..
// jin bhi graph me sorting aajati he waha pe topological sort krna possible nhi he.. 
// question me jo number of courses diye hein that is n value that i snumber of vertices we have..and pre req is basically apne saare ke saae edges ki info..
//cycle aane pe order exist nhi kr skta(toposort)..
// if DAG toh topo sort krna he..
// cycle detection and topo sort use krna he.. 
// topo sort me actually hum isCycle ko hi reuse kr skte hein cz dfs use hota he..
// In topo sort what we really do is hum last me stack me push krdete hein jo store krta he answer in the reverse way...
// i didn't understood recpath and i didn't understood line 68.. i recom watching https://youtu.be/AcppN5XFt24?si=S1_v6FhqCo8RkxB6 and https://youtu.be/rZsgWxodGmM?si=FPnERYBytJfALmt3 again.. kyuki toposort me toh pata chl gya ki just bfs type hota he and sorted ko rev krde toh answer aata he etc..

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCycle(int src,vector<bool> &vis, vector<bool> &recPath, vector<vector<int>> &edges ){
        vis[src] = true;
        recPath[src] = true;

        for(int i = 0; i < edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(src == u){
                if(!vis[v]){
                    if(isCycle(v, vis, recPath, edges)) return true;
                }
                else if (recPath[v]) return true;  
            }
        }

        recPath[src] = false;  
        return false;
    }
        
    void topoSort(int src, vector<bool> &vis, stack <int> &s, vector<vector<int>> &edges){
        vis[src] = true;

        for(int i = 0; i < edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(src == u){
                if(!vis[v]){
                    topoSort(v, vis, s, edges);
                }
            }
        }

        s.push(src);
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector <bool> vis (n,false);
        vector <bool> recPath(n,false);
        vector <int> ans;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(isCycle(i, vis, recPath, edges)){
                    return ans;
                }
            }
        }
        
        //toposort
        stack <int> s;
        vis.assign(n,false);
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                topoSort(i, vis, s, edges);
            }
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n = 4;
    
    // Example: edges = {{1,0},{2,0},{3,1},{3,2}}
    // Means: 0 → 1, 0 → 2, 1 → 3, 2 → 3
    vector<vector<int>> edges = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    vector<int> result = obj.findOrder(n, edges);

    if(result.empty()){
        cout << "Cycle detected or no valid ordering\n";
    } else {
        cout << "Topological Order: ";
        for(int x : result){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

//Main edges ko is tarah treat karta hu ki har pair {v, u} ka matlab hai u → v, yani agar main src node par hu aur koi edge milta hai jisme src == u, toh main v par ja sakta hu. DFS chalate waqt main do arrays maintain karta hu — vis jo batata hai ki node kabhi visit hua hai ya nahi, aur recPath jo current DFS path ko track karta hai. Agar traversal ke dauraan mujhe koi aisa node milta hai jo already recPath me present hai, toh iska matlab cycle hai kyunki main same path me wapas aa gaya. Har DFS call ke end me main recPath[src] = false kar deta hu, jo backtracking represent karta hai. Cycle check hone ke baad, main dubara DFS use karke topological sort banata hu jisme pehle sab reachable nodes visit karta hu aur phir current node ko stack me push karta hu — isse order naturally reverse dependency ke hisaab se milta hai.