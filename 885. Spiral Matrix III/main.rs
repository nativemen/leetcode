struct Solution;

impl Solution {
    pub fn spiral_matrix_iii(rows: i32, cols: i32, r_start: i32, c_start: i32) -> Vec<Vec<i32>> {
        let mut turn_count = 0;
        let mut turn = 0;
        let mut turn_total = 1;
        let total = (rows * cols) as usize;
        let mut row = r_start;
        let mut col = c_start;
        let mut left = c_start;
        let mut right = c_start;
        let mut top = r_start;
        let mut bottom = r_start;
        let mut direction = 0;
        let dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]];
        let mut result = Vec::new();

        while result.len() < total {
            if row >= 0 && row < rows && col >= 0 && col < cols {
                result.push(vec![row, col]);
            }

            turn_count += 1;
            if turn_count == turn_total {
                turn_count = 0;
                turn += 1;
                turn_total = 8 * turn;
                left = c_start - turn;
                right = c_start + turn;
                top = r_start - turn;
                bottom = r_start + turn;
            }

            let mut next_row = row + dirs[direction][0];
            let mut next_col = col + dirs[direction][1];

            if next_row < top || next_row > bottom || next_col < left || next_col > right {
                direction = (direction + 1) % 4;
                next_row = row + dirs[direction][0];
                next_col = col + dirs[direction][1];
            }

            row = next_row;
            col = next_col;
        }

        return result;
    }
}

impl Solution {
    pub fn spiral_matrix_iii(rows: i32, cols: i32, r_start: i32, c_start: i32) -> Vec<Vec<i32>> {
        let total = (rows * cols) as usize;
        let mut step = 1;
        let mut row = r_start;
        let mut col = c_start;
        let mut direction = 0;
        let dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]];
        let mut result = Vec::new();

        while result.len() < total {
            for _ in 0..2 {
                for _ in 0..step {
                    if row >= 0 && row < rows && col >= 0 && col < cols {
                        result.push(vec![row, col]);
                    }

                    row += dirs[direction][0];
                    col += dirs[direction][1];
                }
                direction = (direction + 1) % 4;
            }
            step += 1;
        }

        result
    }
}
