class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string temp = "";
        vector<string> word ;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                word.push_back(temp);
                temp ="";
            }
            else{
                temp += s[i];
            }
        }
        if(temp!="")word.push_back(temp); 
        int n1 = pattern.size();
        int n2 = word.size();
        if(n1 != n2) return false;
         unordered_map<char, string> mp1;  
        unordered_map<string, char> mp2;   

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = word[i];

            if (mp1.count(c) && mp1[c] != w) return false;
            if (mp2.count(w) && mp2[w] != c) return false;

            mp1[c] = w;
            mp2[w] = c;
        }
        return true;
    }
};