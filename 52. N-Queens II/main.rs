struct Solution;

impl Solution {
    pub fn total_n_queens(n: i32) -> i32 {
        if n <= 0 {
            return 0;
        }

        let mut line = vec![0; n as usize];

        return Self::get_count(&mut line, n as usize, 0);
    }

    fn get_count(line: &mut Vec<usize>, size: usize, row: usize) -> i32 {
        if row == size {
            return 1;
        }

        let mut count = 0;

        for col in 0..size {
            if Self::is_valid(line, row, col) {
                line[row] = col;
                count += Self::get_count(line, size, row + 1);
            }
        }

        count
    }

    fn is_valid(line: &Vec<usize>, row: usize, col: usize) -> bool {
        for i in 0..row {
            if line[i] == col
                || i32::abs(row as i32 - i as i32) == i32::abs(col as i32 - line[i] as i32)
            {
                return false;
            }
        }

        true
    }
}

impl Solution {
    pub fn total_n_queens(n: i32) -> i32 {
        if n <= 0 {
            return 0;
        }

        let mut board = vec![vec![false; n as usize]; n as usize];

        return Self::get_count(&mut board, n as usize, 0);
    }

    fn get_count(board: &mut Vec<Vec<bool>>, size: usize, row: usize) -> i32 {
        if row == size {
            return 1;
        }

        let mut count = 0;

        for col in 0..size {
            if Self::is_valid(board, row, col) {
                board[row][col] = true;
                count += Self::get_count(board, size, row + 1);
                board[row][col] = false;
            }
        }

        count
    }

    fn is_valid(board: &Vec<Vec<bool>>, row: usize, col: usize) -> bool {
        for i in 0..=row {
            if board[i][col]
                || (row >= i && col >= i && board[row - i][col - i])
                || (row >= i && col + i < board[i].len() && board[row - i][col + i])
            {
                return false;
            }
        }

        true
    }
}
