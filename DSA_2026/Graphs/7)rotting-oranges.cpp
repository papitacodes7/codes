//leetcode 994th question. //https://leetcode.com/problems/rotting-oranges
//https://youtu.be/RmXo5SWkhCs?si=43mwcbnQLxdFWvDQ 

//view this grid as a diagonal graph.. (from the left side....
// so basically we have to track time for the normal oranges from the source.. jo levels he na woh time ho jaayega for them for example if 0 se start ho rha so for a good orange the time for it would be the level i.e 1(if started from zero)) puraane time me simply +1 krna he.. // there's a thing called multi source bfs.. which means ki multiple source ho skte hein .. for example ek hi toh source nhi hoga.. so jo normal se rotten honge woh like two source..

///////////////////////////////////////////////
//view this grid as a diagonal graph.. (from the left side....
// so basically we have to track time for the normal oranges from the source.. jo levels he na woh time ho jaayega for them for example if 0 se start ho rha so for a good orange the time for it would be the level i.e 1(if started from zero)) puraane time me simply +1 krna he.. 

// there's a thing called multi source bfs.. which means ki multiple source ho skte hein .. for example ek hi toh source nhi hoga.. so jo normal se rotten honge woh like two source..

// so instead of starting BFS from a single cell, we push all the rotten oranges (value = 2) 
// into the queue initially with time = 0, because they are already rotten.

// now BFS works level by level (jo levels he wahi time hai):
// har level pe jo oranges queue me hain woh same time pe rotten hue hain,
// aur unke adjacent fresh oranges (value = 1) next minute me rotten ho jayenge.

// isliye jab bhi hum kisi fresh orange ko visit karte hain,
// hum usse queue me push karte hain with time + 1,
// aur mark kar dete hain visited taki dobara process na ho.

// this ensures ki ek orange minimum possible time me rotten ho,
// kyunki BFS hamesha shortest distance / minimum time deta hai.

// at the end, agar koi fresh orange (1) bacha reh gaya jo visited nahi hua,
// iska matlab woh kisi bhi rotten orange tak reach nahi kar paaya,
// so answer hoga -1.

// otherwise, jo maximum time humne BFS me dekha (ans),
// wahi total minimum time hoga to rot all oranges.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q; //(i,j), time
        vector<vector<bool>> vis(n,vector<bool>(m,false)); 
        int ans = 0;

        // pushing all sources in queue..(sab 2 in q)
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        // bfs
        while(q.size()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();
            ans = max(ans,time);

            //check for all dir..
            // ========================

            //first top i.e i-1,j ->
            if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] == 1){
                q.push({{i-1,j}, time + 1});
                vis[i - 1][j] = true;
            }
            //second bottom i.e i+1,j ->
            if(i+1 < n && !vis[i+1][j] && grid[i+1][j] == 1){
                q.push({{i+1,j}, time + 1});
                vis[i + 1][j] = true;
            }
            //third left i.e i,j-1 ->
            if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] == 1){
                q.push({{i,j-1}, time + 1});
                vis[i][j-1] = true;
            }
            //fourth right i.e i,j+1 ->
            if(j+1 < m && !vis[i][j+1] && grid[i][j+1] == 1){
                q.push({{i,j+1}, time + 1});
                vis[i][j+1] = true;
            }
        }

        //if after bfs still fresh orange left out we can just check using the above for loops xd;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    int result = obj.orangesRotting(grid);
    cout << result << endl;

    return 0;
}