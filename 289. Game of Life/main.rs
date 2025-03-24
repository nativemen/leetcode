struct Solution;

impl Solution {
    pub fn game_of_life(board: &mut Vec<Vec<i32>>) {
        let row_size = board.len() as i32;
        let col_size = board[0].len() as i32;

        for i in 0..row_size {
            for j in 0..col_size {
                let mut count = 0;

                for m in max(0, i - 1)..=min(row_size - 1, i + 1) {
                    for n in max(0, j - 1)..=min(col_size - 1, j + 1) {
                        if m != i || n != j {
                            count += board[m][n] & 1;
                        }
                    }
                }

                if ((board[i][j] & 1) == 1 && count == 2) || count == 3 {
                    board[i][j] |= 1 << 1;
                }
            }
        }

        for i in 0..row_size {
            for j in 0..col_size {
                board[i][j] >>= 1;
            }
        }
    }
}
