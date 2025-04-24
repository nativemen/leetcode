struct Solution;

impl Solution {
    fn make_o2y(board: &mut Vec<Vec<char>>, i: i32, j: i32) {
        if i < 0
            || i >= board.len() as i32
            || j < 0
            || j >= board[0].len() as i32
            || board[i as usize][j as usize] == 'X'
            || board[i as usize][j as usize] == 'Y'
        {
            return;
        }

        board[i as usize][j as usize] = 'Y';

        Self::make_o2y(board, i + 1, j);
        Self::make_o2y(board, i - 1, j);
        Self::make_o2y(board, i, j + 1);
        Self::make_o2y(board, i, j - 1);
    }

    pub fn solve(board: &mut Vec<Vec<char>>) {
        let row_size = board.len();
        let col_size = board[0].len();

        for i in 0..row_size {
            for j in 0..col_size {
                if i == 0 || i == row_size - 1 || j == 0 || j == col_size - 1 {
                    if board[i][j] == 'O' {
                        Self::make_o2y(board, i as i32, j as i32);
                    }
                }
            }
        }

        for i in 0..row_size {
            for j in 0..col_size {
                if board[i][j] == 'O' {
                    board[i][j] = 'X';
                }

                if board[i][j] == 'Y' {
                    board[i][j] = 'O';
                }
            }
        }
    }
}
