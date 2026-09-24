class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // int n;
        // n=0;
        // vector<int>v;
        // int k=0;
        // while(n<nums.size()){
        //     for(int i=n+1;i<nums.size();i++){
        //         if(nums[i]+nums[n]==target){
        //             v.push_back(n);
        //             v.push_back(i);
        //             k=1;
        //             break;
        //         }
                
            
        //     }
        //     n++;
        //     if(k==1){
        //         break;
        //     }
        // }
        // return v;
        vector<int>v;
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            if(map.find(target-nums[i])!=map.end()){
               
                v.push_back(i);
                v.push_back(map[target-nums[i]]);
                break;
            }
            else{
              map.insert(make_pair(nums[i],i));
            }
        }
        return v;
        
    }
};