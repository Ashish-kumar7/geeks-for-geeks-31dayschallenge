class Solution{
    public:
    string Reduced_String(int k,string s){
        // Your code goes here
        stack<pair<char,int>> st;
        st.push({s[0],1});
        for(int i=1;i<s.size();i++){
            if(!st.empty() && st.top().second==k){
                int temp = k;
                while(temp--)
                    st.pop();
            }
            if(!st.empty() && s[i]==st.top().first)
                st.push({s[i],st.top().second + 1});
            else
                st.push({s[i],1});
        }
        if(!st.empty() && st.top().second==k){
            int temp = k;
            while(temp--)
                st.pop();
        }
        string ans;
        while(!st.empty()){
            ans += st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }


};