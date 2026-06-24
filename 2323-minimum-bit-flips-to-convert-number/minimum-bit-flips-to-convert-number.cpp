class Solution {
public:
    string fun(int n)
    {
        string t;
        while(n>0)
        {
            if(n%2==0) t+='0';
            else t+='1';
            n=n/2;
        }
        reverse(t.begin(),t.end());
        return t;
    }
    int minBitFlips(int start, int goal) 
    {
        string s1 = fun(start);
        string s2 = fun(goal);
        int ans = 0;
        int len = max(s1.size(), s2.size());
        while (s1.size()<len) s1 = '0' + s1;
        while (s2.size()<len) s2 = '0' + s2;
        for(int i=0;i<s2.size();i++)
        {
            if(s2[i]!=s1[i]) ans++;
        }
        return ans;
    }
 
};