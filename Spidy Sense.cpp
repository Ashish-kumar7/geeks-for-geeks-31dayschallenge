class Solution{
public:
    
    bool isValid(int x , int y , int M , int N)
    {
        return (x >= 0 && y >= 0 && x < M && y < N);
    }
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
        // Your code goes here
        // here we have to return the shortest path of each open space in the matrix..
        
        vector<vector<int>> res(M , vector<int>(N,-1));
        
        vector<vector<bool>> vis(M,vector<bool>(N,false));
        
        queue<pair<int,pair<int,int>>> q;
        
        for(int i = 0 ; i < M ; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                if(matrix[i][j] == 'B'){
                q.push({0,{i,j}}); // distance and coordinates..
                res[i][j] = 0;
                vis[i][j] = true;
                }
            }
        }
        
        int row[] = {1,-1,0,0};
        int col[] = {0,0,1,-1};
        
        while(!q.empty())
        {
            auto p = q.front();q.pop();
            int dist = p.first;
            int x = p.second.first;
            int y = p.second.second;
            
            //vis[x][y] = true;
            
            for(int i = 0 ; i < 4; i++)
            {
                int nx = x +  row[i];
                int ny = y + col[i];
                
                if(isValid(nx,ny,M,N) && !vis[nx][ny] && matrix[nx][ny] != 'W'){
                    vis[nx][ny] = true;
                    
                    res[nx][ny] = dist+1;
                    q.push({dist+1 , {nx,ny}});
                }
            }
            
        }
        
        return res;

    }  
};
