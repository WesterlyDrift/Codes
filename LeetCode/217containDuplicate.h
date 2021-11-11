#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
class solution1 
{
    public:
        bool containDuplicate1(vector<int> &nums)
        {
            sort(nums.begin(),nums.end());
            for(int i=0;i<nums.size()-1;i++)
            {
                if(nums[i]==nums[i+1])
                return true;
            }
            return false;
        }


        bool containDuplicate2(vector<int>& nums)
        {
            //using hash maps
            unordered_set<int> s;
            for (int x:nums)
            {
                if(s.find(x)!= s.end())
                {
                    return true;
                }
            }
            return false;
        }
        
};
