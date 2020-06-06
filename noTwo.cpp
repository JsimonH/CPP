/* 不要二
二货小易有一个W*H的网格盒子，网格的行编号为0-H-1，网格的列编号为0-W-1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) 的算术平方根
小易想知道最多可以放多少块蛋糕在网格盒子里。
*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int w ,h; //定义列和行
    int ret = 0; //记录存放个数
    cin >> w >> h;
    vector<vector<int>> array;
    //给二维数组开空间并初始化
    array.resize(w);
    for(auto& e : array)
       e.resize(h,1);
    for(int i = 0;i < w;i++)
    {
        for(int j = 0;j < h;j++)
        {
            if(array[i][j] == 1)
            {
                ret++;
                if(j + 2 < h)
                    array[i][j + 2] = 0;
                if(i + 2 < w)
                    array[i + 2][j] = 0;
            }
        }
    }
    cout<<ret<<endl;
    return 0; 
}
