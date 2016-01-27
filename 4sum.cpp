class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> result;
            vector<int> tmp;
            int op=0;
            int size=nums.size();

            if(size < 4)
            {
                result.clear();
                                                                                                
                return result;
                                                                                                        }
            /* sort */
            std::sort(nums.begin(),nums.end());

            /* find quadruplets */
            if((*(nums.begin()) + *(nums.begin()+1) + *(nums.begin()+2) + *(nums.begin()+3)) > target ||
               (*(nums.end()) + *(nums.end()-1) + *(nums.end()-2) + *(nums.end()-3)) < target)
            {
            
                result.clear();
                                                                                                                
                return result;
            }
            if(size == 4)
            {
                result.clear();
                if((*(nums.begin()) + *(nums.begin()+1) + *(nums.begin()+2) + *(nums.begin()+3)) == target)
                {
                    tmp.clear();
                    tmp.push_back(*(nums.begin()+op));
                    tmp.push_back(*(nums.begin()+op+1));
                    tmp.push_back(*(nums.begin()+op+2));
                    tmp.push_back(*(nums.begin()+op+3));

                    result.push_back(tmp);
                }            
                                                                                                                                    
                return result;
            }

            /* 寻找最接近target的四个连续数 */
            for(; op < size-3; op++)
            {
                if((*(nums.begin()+op) + *(nums.begin()+1+op) + *(nums.begin()+2+op) + *(nums.begin()+3+op)) > target)
                {
                    op -= 1;
                    break;
                }
            }
            if(op == (size-3))
            {
                result.clear();
                if((*(nums.begin()+op) + *(nums.begin()+1+op) + *(nums.begin()+2+op) + *(nums.begin()+3+op)) == target)
                {
                    tmp.clear();
                    tmp.push_back(*(nums.begin()+op));
                    tmp.push_back(*(nums.begin()+op+1));
                    tmp.push_back(*(nums.begin()+op+2));
                    tmp.push_back(*(nums.begin()+op+3));

                    result.push_back(tmp);
                }

                return result;
            }

            result.clear();

            for(int i=op-1,j=op+3; j < size; j++)
            {
                if((*(nums.begin()+i) + *(nums.begin()+j-1) + *(nums.begin()+j-2) + *(nums.begin()+j)) < target)
                {
                    continue;
                }

                for(i=op-1; i != -1; i--)
                {
                    if((*(nums.begin()+i) + *(nums.begin()+i+1) + *(nums.begin()+i+2) + *(nums.begin()+j)) > target)
                    {
                        continue;
                    }
                    for(int a=i+1; a< j-1; a++)
                    {
                        for(int b=a+1; b < j; b++)
                        {
                            if((*(nums.begin()+i) + *(nums.begin()+a) + *(nums.begin()+b) + *(nums.begin()+j)) == target)
                            {
                                tmp.clear();
                                tmp.push_back(*(nums.begin()+i));
                                tmp.push_back(*(nums.begin()+a));
                                tmp.push_back(*(nums.begin()+b));
                                tmp.push_back(*(nums.begin()+j));

                                result.push_back(tmp);
                            }
                        }
                    }
                }
            }


            return result;
        }
};
