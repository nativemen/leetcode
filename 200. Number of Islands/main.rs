struct Solution;

impl Solution {
    fn make_islands_zero(grid: &mut Vec<Vec<char>>, i: i32, j: i32) {
        let row_size = grid.len();
        let col_size = grid[0].len();

        if i < 0
            || i >= row_size as i32
            || j < 0
            || j >= col_size as i32
            || grid[i as usize][j as usize] == '0'
        {
            return;
        }

        grid[i as usize][j as usize] = '0';

        Self::make_islands_zero(grid, i - 1, j);
        Self::make_islands_zero(grid, i + 1, j);
        Self::make_islands_zero(grid, i, j - 1);
        Self::make_islands_zero(grid, i, j + 1);
    }

    pub fn num_islands(grid: Vec<Vec<char>>) -> i32 {
        let row_size = grid.len();
        let col_size = grid[0].len();
        let mut count = 0;
        let mut grid = grid;

        for i in 0..row_size {
            for j in 0..col_size {
                if grid[i][j] == '1' {
                    count += 1;
                    Self::make_islands_zero(&mut grid, i as i32, j as i32);
                }
            }
        }

        count
    }
}
