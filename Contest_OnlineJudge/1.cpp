class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        sort(times.begin(), times.end());
        int cnt = 0;
        int n = times.size();
        for(int i = 0; i < n; i++){
            if(i == targetFriend) continue;
            else if(times[i][0] >= times[targetFriend][0] && times[i][1] <= times[targetFriend][1]) cnt++;
        }
        return cnt;
    }
}; 