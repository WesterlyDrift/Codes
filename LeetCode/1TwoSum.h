#include<vector>
class Solution
{
    public:
        template<class t>
        std::vector<t> twosum(std::vector<t>& nums,t target)
        {
            map<t,t> a;
            //establish hash table for storing elements
            vector<t> b(2,-1);
            //Declaring a vector of 2 -1s in it.
            for (int i=0;i<nums.size();i++)
            a.insert(map<t,t>::value_type(nums[i],i));
            for (int i=0;i<nums.size();i++)
            {
                //second chance of hashing
                if(a.count(target-nums[i])>0&&(a[target-nums[i]]!=i))
                //check whether the target is found and cannot be it self
                {
                    b[0]=i;
                    b[1]=a[target-nums[i]];
                    break;
                }
            }
            return b;
        }
};