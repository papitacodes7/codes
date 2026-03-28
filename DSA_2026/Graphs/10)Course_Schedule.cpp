//https://leetcode.com/problems/course-schedule

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCycleDFS(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& recPath) {
        vis[node] = true;
        recPath[node] = true;

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                if (isCycleDFS(neigh, adj, vis, recPath))
                    return true;
            }
            else if (recPath[neigh]) {
                return true; // cycle detected
            }
        }

        recPath[node] = false; // backtrack
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (isCycleDFS(i, adj, vis, recPath))
                    return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    if (sol.canFinish(numCourses, prerequisites))
        cout << "Yes, you can finish all courses\n";
    else
        cout << "No, you cannot finish all courses\n";

    return 0;
}

//iss problem ka scene simple dependency wala hai — har prerequisite [a, b] ka matlab hai ki b pehle karna padega tabhi a kar sakte ho, so graph banega b → a (directed). Ab hume actual order nahi chahiye, bas ye check karna hai ki aisa koi order possible bhi hai ya nahi, jo basically topological sort ka idea hai. Toposort sirf tab possible hota hai jab graph me cycle na ho (DAG ho). Toh pura problem reduce ho jata hai cycle detect karne pe. DFS use karte hain jisme vis batata hai ki node kabhi visit hua hai ya nahi, aur recPath batata hai ki wo node current DFS path me hai. Agar DFS karte time kisi aise node pe pahunch gaye jo already recPath me hai, iska matlab loop ban gaya (cycle) → courses complete nahi ho sakte. Agar kahin bhi cycle nahi mila, toh matlab dependencies valid hain → sab courses complete ho sakte hain.
//https://youtu.be/AcppN5XFt24?si=DvsjLfENbupfJRU0 ye dekh lena..