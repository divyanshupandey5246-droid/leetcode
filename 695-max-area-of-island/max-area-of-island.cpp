class Solution {
public:
void bfs(vector<vector<int>>& grid,int r,int c,int & maxi ,  vector<vector<bool>>&visi ){
         int n=grid.size();
         int m=grid[0].size();
         queue<pair<int,int>>q;
        int count=1;
         visi[r][c]=true;
         q.push({r,c});
         int dr[]={-1,0,+1,0};
         int dc[]={0,1,0,-1};
         while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int row=temp.first;
            int col=temp.second;
            for(int i=0;i<4;i++){
                if(row+dr[i]>=0 && row+dr[i]<n && col+dc[i]>=0 && col+dc[i]<m && grid[row+dr[i]][col+dc[i]] == 1 && !visi[row+dr[i]][col+dc[i]]){
                    visi[row+dr[i]][col+dc[i]]=true;
                  q.push({row+dr[i],col+dc[i]});
                  count++;
                  
                }
                
            }
            maxi=max(count,maxi);

         }
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=0;
        int n=grid.size();
        int m=grid[0].size();
         vector<vector<bool>>visi(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
             if(grid[i][j]==1 && !visi[i][j]){
                bfs(grid,i,j,maxi,visi);
                 
             }
            }
        }
        return maxi;
    }
};