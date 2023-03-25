//Approach -1 O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        //sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};

//Approach -2 Using Maps T.C O(n) S.C O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            int x = nums[i];
            int y = target - x;
            if(m.find(y) != m.end()){
                return {i,m[y]};
            }
            m[nums[i]] = i;
        }
        return {-1,-1};
    }
};

//Approach-3 Two Pointer Approach T.C O(nlogn) S.C O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int> > v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i] ,i});
        }
        sort(v.begin(),v.end());
        int s = 0;
        int e = n - 1;
        while(s<e){
            int sum = v[s].first + v[e].first;
            if(sum == target){
                return {v[s].second,v[e].second};
            }
            else if(sum > target){
                e--;
            }
            else{
                s++;
            }
        }
        return {-1,-1};
    }
};