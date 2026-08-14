class Solution {
public:

    bool helper(int r,int c,vector<vector<char>>& board, string &word, int idx,int m,int n){
        if(idx == word.length()){
            return true;
        }

        if(r<0 || c<0 || c>=n || r>=m || board[r][c] != word[idx]){
            return false;
        }

        char curr = board[r][c];
        board[r][c] = '#';

        bool found = helper(r+1,c,board,word,idx+1,m,n)||
                    helper(r-1,c,board,word,idx+1,m,n)||
                    helper(r,c+1,board,word,idx+1,m,n)||
                    helper(r,c-1,board,word,idx+1,m,n);

        board[r][c] = curr;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                if(helper(i,j,board,word,0,m,n)){
                    return true;
                }
            }
        }
        return false;
    }
};