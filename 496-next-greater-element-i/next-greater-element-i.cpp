class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums2.size();
        
        stack<int> s;
        unordered_map<int, int> mp;

        // Find next greater for every element in nums2
        for(int i = n - 1; i >= 0; i--) {

            while(!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }

            if(s.empty()) {
                mp[nums2[i]] = -1;
            }
            else {
                mp[nums2[i]] = s.top();
            }

            s.push(nums2[i]);
        }

        // Build answer for nums1
        vector<int> res;

        for(int i = 0; i < nums1.size(); i++) {
            res.push_back(mp[nums1[i]]);
        }

        return res;
    }
};