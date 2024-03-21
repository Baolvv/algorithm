/*
 * 54. 螺旋矩阵
 * 给予a,b,c,d四个边界条件，resrict为上下左右四个前进方向
 * 上面第一行走完就将边界缩小1，同理四边通过判断缩小
 * 到达边界改变方向，通过i,j确定位置获取元素
 */
#include <vector>
#include <iostream>

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int a=0, b=matrix[0].size()-1, c=0, d=matrix.size()-1;
        int count=(b+1)*(d+1);
        int i=0, j=0;
        int resrict=0;// 0右，1下，2左，3上
        std::vector<int> result;
        while(count)
        {
            result.emplace_back(matrix[i][j]);
            count--;
            if(resrict==0)
            {
                if(j==b) 
                {
                    c++;
                    resrict=1;
                    i++;
                }
                else
                {
                    j++;
                }
            }
            else if(resrict==1)
            {
                if(i==d) 
                {
                    b--;
                    resrict=2;
                    j--;
                }
                else
                {
                    i++;
                }
            }
            else if(resrict==2)
            {
                if(j==a) 
                {
                    d--;
                    resrict=3;
                    i--;
                }
                else
                {
                    j--;
                }
            }
            else if(resrict==3)
            {
                if(i==c) 
                {
                    a++;
                    resrict=0;
                    j++;
                }
                else
                {
                    i--;
                }
            }
        }
        return result;
    }

// std::vector<int> solution(std::vector<std::vector<int>>& matrix) {
//     int a=0, b=matrix.size(), c=0, d=matrix[0].size();
//     int count=b*d;
//     std::vector<int> result;
//     while(count)
//     {
//         for(int i=c;i<d-1;i++)
//         {
//             result.emplace_back(matrix[a][i]);
//             count--;
//         }
//     }
// }

int main()
{
    std::vector<std::vector<int>> martic = {{1,2,3},{4,5,6},{7,8,9}};
    std::vector<int> result = spiralOrder(martic);

    for(int i=0;i<result.size();i++)
    {
        std::cout<<result[i]<<std::endl;
    }

    return 0;
}