class Solution {
public:
    bool isBalanced(string num) {
        int even = 0;
        int odd = 0;
 
        for(int i = 0; i < num.length(); i += 2){
            even += num[i] - '0';
        }
 
        for(int i = 1; i < num.length(); i += 2){
            odd += num[i] - '0';
        }
 
        return even == odd;
    }
};