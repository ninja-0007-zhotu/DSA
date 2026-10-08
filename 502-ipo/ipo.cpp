class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> minHeap;
        
        priority_queue<int> maxHeap;
        
        int n = profits.size();

        for(int i = 0; i < n; i++) {
            minHeap.push({capital[i], profits[i]});
        }

        while(k--) {
            
            // Put all affordable projects into max heap
            while(!minHeap.empty() && minHeap.top().first <= w) {
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }

            // No project can be done
            if(maxHeap.empty())
                break;

            // Choose maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};