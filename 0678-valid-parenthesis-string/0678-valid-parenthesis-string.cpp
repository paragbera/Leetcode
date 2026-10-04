class Solution {
public:
    
    bool solve(int idx, int cnt, string &s, vector<vector<int>> &dp){

        if(cnt < 0) return false;

        if(idx == s.size()) return cnt == 0;

        if(dp[idx][cnt] != -1) return dp[idx][cnt];

        bool ans = false;

        if(s[idx] == '(') ans = solve(idx + 1, cnt + 1, s, dp);

        else if(s[idx] == ')') ans = solve(idx + 1, cnt - 1, s, dp);

        else{

            ans |= solve(idx + 1, cnt + 1, s, dp);
            ans |= solve(idx + 1, cnt - 1, s, dp);
            ans |= solve(idx + 1, cnt, s, dp);
        }

        return dp[idx][cnt] = ans;
    }
    
    bool checkValidString(string s) {
        
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, 0, s, dp);
    }
};