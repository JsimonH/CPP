/* 井字棋
对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为-1代表是对方玩家的棋子。
*/

class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        //判断行
        for(int i = 0; i < board.size(); ++i)
        {
            if(board[i][0] == board[i][1] 
               && board[i][0] == board[i][2] 
               && board[i][0] == 1)
            {
                return true;
            }
        }
        
        //判断列
        for(int j = 0; j < board[0].size(); ++j)
        {
            if(board[0][j] == board[1][j]
               && board[0][j] == board[2][j] 
               && board[0][j] == 1)
            {
                return true;
            }
        }
       
       //判断对角线
       if(board[0][0] == board[1][1]
          && board[0][0] == board[2][2]
          && board[0][0] == 1)
       {
           return true;
       }
       if(board[2][0] == board[1][1]
          && board[2][0] == board[0][2] 
          && board[2][0] == 1)
       {
           return true;
       }
       
       return false;
    }
};
