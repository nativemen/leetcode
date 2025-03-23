struct Solution;

impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let row_size = matrix.len();
        let col_size = matrix[0].len();
        let mut rows = vec![false; row_size];
        let mut cols = vec![false; col_size];

        for i in 0..row_size {
            for j in 0..col_size {
                if matrix[i][j] == 0 {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for i in 0..row_size {
            if rows[i] {
                for j in 0..col_size {
                    matrix[i][j] = 0;
                }
            }
        }

        for j in 0..col_size {
            if cols[j] {
                for i in 0..row_size {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}

impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let row_size = matrix.len();
        let col_size = matrix[0].len();
        let mut rows = vec![false; row_size];
        let mut cols = vec![false; col_size];

        for i in 0..row_size {
            for j in 0..col_size {
                if matrix[i][j] == 0 {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for i in 0..row_size {
            for j in 0..col_size {
                if rows[i] || cols[j] {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}

impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let row_size = matrix.len();
        let col_size = matrix[0].len();
        let mut first_row_has_zero = false;
        let mut first_col_has_zero = false;

        for j in 0..col_size {
            if matrix[0][j] == 0 {
                first_row_has_zero = true;
            }
        }

        for i in 0..row_size {
            if matrix[i][0] == 0 {
                first_col_has_zero = true;
            }
        }

        for i in 1..row_size {
            for j in 1..col_size {
                if matrix[i][j] == 0 {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for i in 1..row_size {
            if matrix[i][0] == 0 {
                for j in 1..col_size {
                    matrix[i][j] = 0;
                }
            }
        }

        for j in 1..col_size {
            if matrix[0][j] == 0 {
                for i in 1..row_size {
                    matrix[i][j] = 0;
                }
            }
        }

        if first_row_has_zero {
            for j in 0..col_size {
                matrix[0][j] = 0;
            }
        }

        if first_col_has_zero {
            for i in 0..row_size {
                matrix[i][0] = 0;
            }
        }
    }
}

impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let row_size = matrix.len();
        let col_size = matrix[0].len();
        let mut first_row_has_zero = false;
        let mut first_col_has_zero = false;

        for i in 0..row_size {
            for j in 0..col_size {
                if matrix[i][j] == 0 {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;

                    if i == 0 {
                        first_row_has_zero = true;
                    }
                    if j == 0 {
                        first_col_has_zero = true;
                    }
                }
            }
        }

        for i in 1..row_size {
            for j in 1..col_size {
                if matrix[i][0] == 0 || matrix[0][j] == 0 {
                    matrix[i][j] = 0;
                }
            }
        }

        if first_col_has_zero {
            for i in 0..row_size {
                matrix[i][0] = 0;
            }
        }

        if first_row_has_zero {
            for j in 0..col_size {
                matrix[0][j] = 0;
            }
        }
    }
}

impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let row_size = matrix.len();
        let col_size = matrix[0].len();
        let zeros = matrix
            .iter()
            .enumerate()
            .flat_map(|(i, row)| {
                row.iter()
                    .enumerate()
                    .filter(|&(_, &value)| value == 0)
                    .map(move |(j, _)| (i, j))
            })
            .collect::<Vec<_>>();

        for (i, j) in zeros {
            for k in 0..row_size {
                matrix[k][j] = 0;
            }

            for k in 0..col_size {
                matrix[i][k] = 0;
            }
        }
    }
}
