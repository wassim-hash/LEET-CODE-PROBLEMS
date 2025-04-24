//https://leetcode.com/problems/contains-duplicate-ii/?envType=problem-list-v2&envId=sliding-window

class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            
            unordered_set<int>m;
            for(int i=0;i<nums.size();i++){
                if(m.count(nums[i])){
                    return true;    // if we found a duplicate in the subarray of length k we return true
                }
                m.insert(nums[i]); // if the value doesn't exist we add it to our set to check for it in the future if needed 

                if(m.size()>k){
                    m.erase(nums[i-k]);  // we keep our window matching the demanded criteria which is abs(i-j)<=k
                }
            }
            return false;
        }

        bool containsNearbyDuplicate2(vector<int>& nums, int k) {
            
            //this second approach  uses the map instead of sliding window
            unordered_map<int,int>seen;

            for(int i=0;i<nums.size();i++){
                if(seen.count(nums[i]) && abs(i-seen[nums[i]] )<=k ){
                    return true;    // if found a duplicate that is in range 
                }
                seen[nums[i]]=i; //else we update the index stored in the so we check always for the closest duplicate
            }  
            return false;
        }
    };