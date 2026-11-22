class Solution {
public:
    int p[26];

    int find(int x){
        return p[x]==x?x:p[x]=find(p[x]);
    }

    bool equationsPossible(vector<string>& e) {
        iota(p,p+26,0);

        for(auto s:e)
            if(s[1]=='=')
                p[find(s[0]-'a')]=find(s[3]-'a');

        for(auto s:e)
            if(s[1]=='!' && find(s[0]-'a')==find(s[3]-'a'))
                return false;

        return true;
    }
};