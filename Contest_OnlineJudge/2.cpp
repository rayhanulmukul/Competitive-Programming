class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        map <char, int> mp;
        
        for(int i = 0; i < n; i++){
            if(i == 0){
                string temp = words[i];
                for(auto it : temp) mp[it]++;
            }
            else{
                string temp = words[i];
                for(auto it : temp){
                    if(mp[it]) 
                }
            }
        }   
    }
};