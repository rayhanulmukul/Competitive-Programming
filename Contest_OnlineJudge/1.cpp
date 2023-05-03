class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int sum1 = 0;
        int sum2 = 0;
        int flag = 0;
        for(int i = 0; i < player1.size(); i++){
            sum1 += (flag > 0) ? 2*player1[i] : player1[i];
            flag--;
            if(player1[i] == 10) flag = 2;
        }
        flag = 0;
        for(int i = 0; i < player2.size(); i++){
            sum2 += (flag > 0) ? 2*player2[i] : player2[i];
            flag--;
            if(player2[i] == 10) flag = 2;
        }
        if(sum1 == sum2){
            return 0;
        }
        else if(sum1 > sum2){
            return 1;
        }
        else{
            return 2;
        }

    }
};