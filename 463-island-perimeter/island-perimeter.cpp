class Solution {
public:
    void bfs(vector<vector<int>>& grid,int r,int c,int & peri){
         int n=grid.size();
         int m=grid[0].size();
         queue<pair<int,int>>q;
         vector<vector<bool>>visi(n,vector<bool>(m,false));
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

                }
                 else if(row+dr[i] < 0 ||  row+dr[i]>= n || col+dc[i]< 0 || col+dc[i] >= m) {
                peri++;
            }
                else if(grid[row+dr[i]][col+dc[i]] == 0){
                    peri++;
                }
            }

         }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri=0;
        int r=grid.size();
        int c=grid[0].size();
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
             if(grid[i][j]==1){
                bfs(grid,i,j,peri);
                 return peri;
             }
            }
        }
        return peri;
    }
};