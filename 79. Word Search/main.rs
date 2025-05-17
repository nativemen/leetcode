struct Solution;

impl Solution {
    pub fn exist(board: Vec<Vec<char>>, word: String) -> bool {
        let mut board = board;

        for i in 0..board.len() as i32 {
            for j in 0..board[i as usize].len() as i32 {
                if Self::dfs(&mut board, word.as_bytes(), 0, i, j) {
                    return true;
                }
            }
        }

        return false;
    }

    fn dfs(board: &mut Vec<Vec<char>>, word: &[u8], index: usize, i: i32, j: i32) -> bool {
        if index == word.len() {
            return true;
        }

        if i < 0
            || i >= board.len() as i32
            || j < 0
            || j >= board[i as usize].len() as i32
            || board[i as usize][j as usize] != word[index] as char
        {
            return false;
        }

        board[i as usize][j as usize] = '#';
        let r1 = Self::dfs(board, word, index + 1, i - 1, j);
        let r2 = Self::dfs(board, word, index + 1, i + 1, j);
        let r3 = Self::dfs(board, word, index + 1, i, j - 1);
        let r4 = Self::dfs(board, word, index + 1, i, j + 1);
        board[i as usize][j as usize] = word[index] as char;

        return r1 || r2 || r3 || r4;
    }
}
