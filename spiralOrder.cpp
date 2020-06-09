/* 顺时针打印矩阵
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> res;
        if(matrix.empty()) 
            return res;
        int row = 0, rowMax = matrix.size()-1; 
        int col = 0, colMax = matrix[0].size()-1;
        while(1)
        {
            for(int i = col; i <= colMax; ++i)   //从左往右
                res.push_back(matrix[row][i]);
            if(++row > rowMax) break;
            
            for(int i = row; i <= rowMax; ++i)   //从上往下
                res.push_back(matrix[i][colMax]);
            if(--colMax < col) break;
            
            for(int i = colMax; i >= col; --i)   //从右往左
                res.push_back(matrix[rowMax][i]);
            if(--rowMax < row) break;
           
            for(int i = rowMax; i >= row; --i)   //从下往上
                res.push_back(matrix[i][col]);
            if(++col > colMax) break;
        }
        return res;
    }
};
