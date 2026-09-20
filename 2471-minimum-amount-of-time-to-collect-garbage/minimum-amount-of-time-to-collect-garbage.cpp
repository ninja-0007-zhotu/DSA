class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int g=0,p=0,m=0,gl=-1,pl=-1,ml=-1;
        for(int i=1;i<travel.size();i++){
            travel[i]+=travel[i-1];
        }
        for(int i=0;i<garbage.size();i++){
            for(int j=0;j<garbage[i].length();j++){
                if(garbage[i][j]=='G'){
                    g++;
                    gl=i-1;
                }
                else if(garbage[i][j]=='P'){
                    p++;
                    pl=i-1;
                }
                else if(garbage[i][j]=='M'){
                    m++;
                    ml=i-1;
                }
            }
        }
        return g+p+m+(gl==-1?0:travel[gl])+(pl==-1?0:travel[pl])+(ml==-1?0:travel[ml]);
        
    }
};