class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low=0;
        int n=arr.size();
        int high=n-1;
        
        while(low<=high){
            int mid=low+(high-low)*0.5;
            if(arr[mid]==target){
                     return mid;
            }
            else if(arr[mid]>target){
            
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return -1;
    }
};