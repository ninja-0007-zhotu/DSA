class Solution {
public:
    int hammingWeight(int n) {
       int setBits = 0;
        while(n!=0){
            int remainder = n%2;
            if(remainder){
                setBits++;
            }
            n/=2;
        }
        return setBits; 
    }
};