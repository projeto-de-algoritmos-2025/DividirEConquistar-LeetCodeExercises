#include <vector>

using namespace std;

class BIT {
private:
    vector<int> tree; 
    int n;          

public:
    BIT(int size) {
        this->n = size;
        tree.resize(n + 1, 0); 
    }


    void add(int val) {
        int idx = val + 1; 
        while (idx <= n) {
            tree[idx]++;
            idx += idx & (-idx); 
        }
    }


    int query(int val) {
        int idx = val + 1; 
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & (-idx); 
        }
        return sum;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        vector<int> pos2(n);
        for (int i = 0; i < n; ++i) {
            pos2[nums2[i]] = i;
        }

        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            A[i] = pos2[nums1[i]];
        }

        vector<long long> left_counts(n);
        BIT bit_left(n); 

        for (int i = 0; i < n; ++i) {
            int val = A[i];
            left_counts[i] = bit_left.query(val - 1);
            
            bit_left.add(val);
        }

        vector<long long> right_counts(n);
        BIT bit_right(n); 

        for (int i = n - 1; i >= 0; --i) {
            int val = A[i];
            
            int total_seen = bit_right.query(n - 1); 
            
            int le_val = bit_right.query(val);

            right_counts[i] = total_seen - le_val;

            bit_right.add(val);
        }
        long long total_triplets = 0;
        for (int i = 0; i < n; ++i) {
            total_triplets += left_counts[i] * right_counts[i];
        }

        return total_triplets;
    }
};