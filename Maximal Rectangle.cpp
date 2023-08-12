class Solution {
public:
    int f(vector<int>& v)
    {
        int n=v.size();
        vector<int> left_smaller(n),right_smaller(n);
        stack<int> s1,s2;

        for(int i=0 ; i<n ; i++)
        {
            while(s1.size()!=0 && v[s1.top()]>=v[i]) s1.pop();
            if(s1.empty()) left_smaller[i] = 0;
            else left_smaller[i] = s1.top()+1;
            s1.push(i);
        }

        for(int i=n-1 ; i>=0 ; i--)
        {
            while(s2.size()!=0 && v[s2.top()]>=v[i]) s2.pop();
            if(s2.empty()) right_smaller[i] = n-1;
            else right_smaller[i] = s2.top()-1;
            s2.push(i);
        }

        int ans = 0;
        for(int i=0 ; i<n ; i++)
        {
            ans = max(ans, v[i]*(right_smaller[i]-left_smaller[i]+1) );
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> v(m,0);
        int ans = 0;
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(matrix[i][j]=='0') v[j]=0;
                else v[j]+=1;
            }
            ans = max(ans,f(v));
        }
        return ans;
    }
};
