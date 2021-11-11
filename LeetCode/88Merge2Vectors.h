#include<vector>
#include<iomanip>
class Solution
{
    public:
        void merge(std::vector<int>& nums1,int m,std::vector<int>& nums2,int n)
        {
            std::vector<int> temp=nums1;
            int pointer=nums1.size()-1;
            m--;
            n--;
            while(m>=0)
            {
                while(n>=0&&nums1[m]<nums2[n])
                {
                    std::swap(nums1[pointer--],nums2[n--]);
                }
            }
                std::swap(nums1[pointer--],nums1[m--]);
         
        }
};