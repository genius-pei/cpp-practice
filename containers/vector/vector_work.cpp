#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//杨辉三角
class Solution1 {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> xx;
        xx.resize(numRows);//为每行开辟空间
        for (size_t i = 0;i < numRows;++i)//为个数开辟空间
        {
            xx[i].resize(i + 1, 1);
        }
        for (size_t i = 2;i < numRows;++i)//插入每个数
        {
            for (size_t j = 1;j < xx[i].size() - 1;++j)
            {
                xx[i][j] = xx[i - 1][j] + xx[i - 1][j - 1];
            }
        }
        return xx;
    }
};
int main() {
    Solution1 sol;
    int numRows = 10;
    vector<vector<int>> result = sol.generate(numRows);
    for (const auto& row : result) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
//——————————————————————————————————————————

//只出现一次的数字
class Solution2 {
public:
    int singleNumber(vector<int>& nums)
    {
        int x = 0;
        for (auto e : nums)
        {
            x ^= e;//重复出现的按位操作后会归零
        }
        return x;
    }
};
//————————————————————————————————————————————
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        unsigned int arr = 0;
        for (auto e : nums)//得到两个不同数的异或结果
        {
            arr ^= e;
        }

        int distinguish = arr & -arr;//用于区分两个不同的数，得到最近一为不同的1
        vector<int> ans(2);
        for (auto e : nums)
        {
            if ((e & distinguish) == 0)//分为两组
            {
                ans[0] ^= e;
            }
            else
                ans[1] ^= e;
        }
        return ans;
    }

};
//————————————————————————————————————
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int cond = -1;
        int cnt = 0;
        for (int i = 0; i < numbers.size(); ++i) //将数组中的数进行比较，不相同就消去，最后留下的检验是否为众数
        {
            if (cnt == 0) {
                cond = numbers[i];
                ++cnt;
            }
            else {
                if (cond == numbers[i]) ++cnt;
                else --cnt;
            }

        }
        cnt = 0;
        for (const int k : numbers) {
            if (cond == k) ++cnt;
        }
        if (cnt > numbers.size() / 2) return cond;
        return 0;
    }
};
