class Solution {
public:
    string getPermutation(int n, int k) {
        vector <int> nums ;
        int fact = 1; 
        for(int i = 1 ; i<n ;i++){
            fact*=i ;
        }
        for(int i =1  ; i<=n ; i++){
            nums.push_back(i);
        }
        k-- ;
        string ans = ""; 
        while(true){
            int index = k/fact;
            ans += to_string(nums[index]);
            nums.erase(nums.begin()+index);
            if (nums.size()==0) break ;
            k = k%fact ;
            fact =  fact /nums.size();
        }
        return ans ;
    }
};