class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), [](vector <int>& a, 
        vector <int>& b){
            return a[1] < b[1];
        });

        int second = 0, first = 0;
        int first = events[0][1];
        for(int i = 0; i < n; i++){
            second = events[i][0];

            if(first <= second) cnt++;
            first = second;
        }
        return cnt;
    }
};