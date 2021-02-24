class comp{
    public:
    bool operator()(const pair<int,int>&a,const pair<int,int>&b){
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first > b.first ;
        }
};
class Solution{
    public:
       
    vector<int> Kclosest(vector<int>arr, int n, int x, int k) { 
        // Your code goes here 
        priority_queue< pair<int,int>,vector<pair<int,int>>,comp >pq;
        // priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<arr.size();i++){
            pq.push({abs(x-arr[i]) , arr[i]});
        }
        vector<int>ans;
        
        while(k--){
            pair<int,int>pr=pq.top();
            pq.pop();
            ans.push_back(pr.second);
        }
        sort(ans.begin(),ans.end());
     return ans;   
    }
   
};
