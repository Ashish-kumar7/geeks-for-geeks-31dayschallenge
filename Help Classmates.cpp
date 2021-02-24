class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        stack<int>S;
        vector<int>ans;
        
        for(int i=n-1;i>=0;i--){
            
            
            while(!S.empty() && arr[i]<=S.top()){
                S.pop();
            }
            if(S.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(S.top());
            }
            S.push(arr[i]);
            
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    } 
};