/*
 * 289. 生命游戏
 * 循环遍历每一个位置，判断旁边四个位置的生或死
 * -1生变死，2死变生，因此0，2为死，1，-1为生
 * 遍历完后再遍历一遍消除2和-1
 */
#include <vector>
#include <iostream>

void gameOfLife(std::vector<std::vector<int>>& board) {
        // -1生变死，2死变生
        int a=board.size(), b=board[0].size();
        int died=0, live=0;
        std::vector<std::vector<int>> res={{-1,-1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                for(int k=0;k<res.size();k++)
                {
                    if(i+res[k][0]>=a||j+res[k][1]>=b||i+res[k][0]<0||j+res[k][1]<0)
                    {
                        died++;
                        continue;
                    }
                    int temp=board[i+res[k][0]][j+res[k][1]];
                    if(temp==0||temp==2) died++;
                    else if(temp==1||temp==-1) live++;
                }
                if(board[i][j]==0&&live==3)
                {
                    board[i][j]=2;
                }
                else if(board[i][j]==1&&(live<2||live>3))
                {
                    board[i][j]=-1;
                }
                live=0;
                died=0;
            }
        }
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                if(board[i][j]==-1) board[i][j]=0;
                else if(board[i][j]==2) board[i][j]=1;
            }
        }
    }

int main()
{
    std::vector<std::vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    gameOfLife(board);
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            std::cout<<board[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}