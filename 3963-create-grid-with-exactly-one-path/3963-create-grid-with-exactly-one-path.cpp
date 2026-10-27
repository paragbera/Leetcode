class Solution {
public:
    vector<string> createGrid(int m, int n) {
        
        vector<string> ans;

        string s;

        for(int i = 0; i < n; i++){
            char ch = '.';
            s += ch;
        }

        ans.push_back(s);

        for(int i = 1; i < m; i++){
            string temp;
            for(int i = 0; i < n; i++){
                char ch = '#';

                if(i == (n - 1)) ch = '.';

                temp += ch;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};