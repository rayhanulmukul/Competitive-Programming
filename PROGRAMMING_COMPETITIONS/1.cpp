class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector <int> ans;
        int n = code.size();
        for(int i = 0; i < n; i++){
            if(k > 0){
                int j = (i + 1) % n;
                int cnt = 0;
                int sum = code[j];
                while(cnt < k){
                    j = (j + 1) % n;
                    cnt++;
                    sum += code[j];
                }
                ans.push_back(sum);
            }
            else if(k == 0){
                ans.push_back(0);
            }
            else{
                int j = (i + k);
                if(j < 0) j = n + j;
                int cnt = 0;
                int sum = code[j];
                while(cnt < k){
                    j = (j + 1) % n;
                    cnt++;
                    sum += code[j];
                }
                ans.push_back(sum);
            }
        }
        return ans;
    }
};