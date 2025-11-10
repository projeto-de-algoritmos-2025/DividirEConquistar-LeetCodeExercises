#include <vector>
#include <algorithm>
#include <set> 

using namespace std;

class Solution {
public:
    vector<int> ans;
    void solve(int k, vector<int> current_sums) {
        if (k == 0) {
            return;
        }

        sort(current_sums.begin(), current_sums.end());
        int d = current_sums[1] - current_sums[0];

        multiset<int> counts;
        for (int s : current_sums) {
            counts.insert(s);
        }

        vector<int> s1; 
        vector<int> s2; 
        
        bool zero_in_s1 = false;

        while (!counts.empty()) {
            int s = *counts.begin();
            counts.erase(counts.begin());
            auto it = counts.find(s + d);
            counts.erase(it);
            s1.push_back(s);
            s2.push_back(s + d);
            if (s == 0) {
                zero_in_s1 = true;
            }
        }
        
        if (zero_in_s1) {
            ans.push_back(d);
            solve(k - 1, s1);
        } else {
            ans.push_back(-d);
            solve(k - 1, s2); 
        }
    }

    vector<int> recoverArray(int n, vector<int>& sums) {
        ans.clear();
        solve(n, sums);
        return ans;
    }
};