/*
 * 48. 旋转图像
 * 先将矩阵水平翻转
 * 再将矩阵以对角线翻转
 */
#include <vector>
#include <iostream>

void rotate(std::vector<std::vector<int>>& matrix) {
        int size = matrix[0].size();
        for(int i=0;i<size/2;i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                std::swap(matrix[i][j], matrix[size-1-i][j]);
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

int main()
{
    std::vector<std::vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(a);
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[0].size();j++)
        {
            std::cout<<a[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}