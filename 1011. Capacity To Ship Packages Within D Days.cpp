#include <bits/stdc++.h>    
using namespace std;

class Solution {
public:
    // Yeh function check karega ki agar ship ki capacity `cap` ho,
    // toh saara weight ship karne me kitne din lagenge
    int findDays(vector<int>& weights, int cap) {
        int days = 1, load = 0; // Pehle ek din maan ke chalte hain
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] + load > cap) { 
                // Agar current weight add karne se capacity exceed ho gayi
                days++; // Naya din shuru karna padega
                load = weights[i]; // Naye din ka load start hoga is weight se
            } 
            else {
                // Agar capacity exceed nahi hui toh bas load badha do
                load += weights[i];
            }
        }
        return days; // Total din return kar do
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // `low` = sabse bada weight kyunki ek din me at least itna load toh uthana padega
        int low = *max_element(weights.begin(), weights.end()); 
        
        // `high` = saare weights ka total sum kyunki worst case me ek din me sabhi weights le jane pad sakte hain
        int high = accumulate(weights.begin(), weights.end(), 0); 
        
        while (low <= high) {
            int mid = (low + high) / 2; // Mid capacity maan lo
            int dineeds = findDays(weights, mid); // Is capacity pe kitne din lagenge

            if (dineeds <= days) { 
                // Agar given `days` ke andar ho raha hai, toh capacity aur kam karne ka try karo
                high = mid - 1; 
            } 
            else { 
                // Agar `days` se zyada lag rahe hain toh capacity badhani padegi
                low = mid + 1;
            }
        }
        return low; // Minimum required capacity return karo
    }
};
