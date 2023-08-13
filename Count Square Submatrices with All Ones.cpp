// tabulation
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m];
        for(int i=0 ; i<m ; i++) dp[0][i] = matrix[0][i];
        for(int i=0 ; i<n ; i++) dp[i][0] = matrix[i][0];
        int ans = 0;

        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(i==0 || j==0)
                {
                    if(matrix[i][j] == 1) ans++;
                    continue;
                }
                if(matrix[i][j]==0) dp[i][j] = 0;
                else dp[i][j] = 1+min(dp[i-1][j-1] , min(dp[i-1][j],dp[i][j-1]));
                ans+=dp[i][j];
            }
        }

        return ans;
    }
};
// tabulation

// space opti
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m) , cur(m);
        int ans = 0;
        for(int i=0 ; i<m ; i++) 
        {
            prev[i] = matrix[0][i];
            if(matrix[0][i] == 1) ans++;
        }

        for(int i=1 ; i<n ; i++)
        {
            cur[0] = matrix[i][0];
            if(cur[0] == 1) ans++;

            for(int j=1 ; j<m ; j++)
            {
                if(matrix[i][j]==0) cur[j] = 0;
                else cur[j] = 1+min(prev[j-1] , min(prev[j],cur[j-1]));
                ans+=cur[j];
            }
            prev = cur;
        }

        return ans;
    }
};
// space opti
