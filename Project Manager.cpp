int visited[100005];
int counted[100005];
int isstack[100005];


class Solution{
    public:
    // refer https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
    // for cycle detection in directed graph
    bool checkCycle(int i, vector<vector<int>> &ve) {
        if (isstack[i] == 1) return true;
    
        // insert into stack
        isstack[i] = 1;
        for (auto it : ve[i]) {
            // if next node is visited
            if (visited[it] == 1) {
                // if the node is in stack then cycle is found
                if (isstack[it] == 1) return true;
                continue;
            }
            visited[it] = 1;
            if (checkCycle(it, ve)) return true;
        }
        // removing from stack
        isstack[i] = 0;
        return false;
    }
    /*
        i: current node
        ve: adjacency list of the graph
        duration: time to complete each module
    */
    int dfs(int i, vector<vector<int>> &ve, int duration[]) {
        // return the time to complete the project starting from the node i if it is
        // already calculated
        if (counted[i] != -1) return counted[i];
        int x = 0;
    
        for (auto it : ve[i]) x = max(x, dfs(it, ve, duration));
    
        // time to complete this module and maximum time to complete child modules
        counted[i] = x + duration[i];
        return counted[i];
    }
    
    int minTime(vector<pair<int, int>> &vp, int duration[], int n, int m) {
        // stores which modules are independent
        int independent[n + 5] = {0};
        // create a graph from the dependency vector
        vector<vector<int>> ve(n + 2);
        for (int i = 0; i < m; i++) {
            int x = vp[i].first;
            int y = vp[i].second;
            ve[x].push_back(y);
            independent[y]++;
        }
        memset(visited, -1, sizeof(visited));
        memset(counted, -1, sizeof(counted));
        memset(isstack, -1, sizeof(isstack));
    
        int flag = 0;
        for (int i = 0; i < n; i++)
            if (independent[i] == 0) flag = 1;
    
        // if there is no independent module then the project can't be completed
        if (flag == 0) return -1;
    
        for (int i = 0; i < n; i++) {
            if (independent[i] != 0) {
                continue;
            }
            visited[i] = 1;
            // check if cycle is exist then project can't be completed
            if (checkCycle(i, ve)) return -1;
        }
    
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (independent[i] == 0) ans = max(ans, dfs(i, ve, duration));
    
        return ans;
    }
};

