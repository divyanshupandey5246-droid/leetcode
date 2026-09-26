class Solution {
public:
     bool bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j,vector<vector<bool>>&visi){
        queue<pair<int ,int>>q;
        q.push({i,j});
        visi[i][j]=true;
         bool ans = true;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int row=temp.first;
            int col=temp.second;
              if(grid1[row][col] == 0){
                ans = false;
            }

            for(int i=0;i<4;i++){
                  int newr = row + dr[i];
                int newc = col + dc[i];

                if(newr >= 0 && newr < grid2.size() &&
                   newc >= 0 && newc < grid2[0].size() &&
                   grid2[newr][newc] == 1 &&
                   !visi[newr][newc]){
                    
                    visi[newr][newc] = true;
                    q.push({newr,newc});
                }
            }
            }
        
        return ans;
     }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count=0;
        int m=grid2.size();
        int n=grid2[0].size();
        vector<vector<bool>>visi(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(!visi[i][j] && grid2[i][j]==1){
                 if(bfs(grid1,grid2,i,j,visi)){
                        count++;
                    }
              }
            }
        }
        return count;
    }
};