class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int sz = nums.size();
            unordered_map <int, int> freq;
            int i = 0;
            for(i = sz - 1; i >= 0; i--){
                if(freq[nums[i]]){
                    break;
                }
                freq[nums[i]]++;
            }
            i++;
            return ceil(i / 3.0);
        }
    };