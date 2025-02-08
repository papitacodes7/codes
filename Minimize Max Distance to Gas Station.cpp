#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stations, double mid, int k)
{
    int total = 0; // total number of stations jo hume insert karne padenge
    for (int i = 1; i < stations.size(); i++)
    {
        int dis = stations[i] - stations[i - 1]; // current gap calculate kar rahe hai
        total += ceil(dis / mid) - 1;            // required stations ka count update kar rahe hai
    }
    return total <= k; // agar total <= k hai toh possible hai
}

// yeh function minimum maximum distance ko find karega
double findSmallestMaxDist(vector<int> &stations, int k)
{
    int n = stations.size(); // total number of stations
    double low = 0, high = stations[n - 1] - stations[0], mid = 0, ans = high;

    // Binary search apply karenge to find minimum maximum distance
    while (high - low >= 1e-6)
    {                           // precision maintain karne ke liye (10^-6 tak search karenge)
        mid = (low + high) / 2; // mid value calculate kar rahe hai (potential max distance)

        // Check kar rahe hain ki agar 'mid' distance rakh kar k stations place kar sakte hain ya nahi
        if (isPossible(stations, mid, k))
        {
            ans = mid;  // agar possible hai toh answer ko update karenge
            high = mid; // search space ko left shift karenge (kyunki hume aur chhoti value chahiye)
        }
        else
        {
            low = mid; // agar nahi possible hai toh right side search karenge
        }
    }
    return ans; // final answer return karenge jo minimum max distance hoga
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = findSmallestMaxDist(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}