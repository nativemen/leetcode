struct Solution;

impl Solution {
    pub fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let row_size = grid.len();
        let col_size = grid[0].len();
        let mut grid = grid;

        for row in 1..row_size {
            grid[row][0] += grid[row - 1][0];
        }

        for col in 1..col_size {
            grid[0][col] += grid[0][col - 1];
        }

        for row in 1..row_size {
            for col in 1..col_size {
                grid[row][col] += grid[row - 1][col].min(grid[row][col - 1]);
            }
        }

        grid[row_size - 1][col_size - 1]
    }
}
