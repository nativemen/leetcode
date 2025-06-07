struct Solution;

impl Solution {
    pub fn unique_paths_iii(grid: Vec<Vec<i32>>) -> i32 {
        fn dfs(grid: &mut Vec<Vec<i32>>, i: i32, j: i32, spaces: i32) -> i32 {
            let row_size = grid.len();
            let col_size = grid[0].len();

            if i < 0
                || i >= row_size as i32
                || j < 0
                || j >= col_size as i32
                || grid[i as usize][j as usize] == -1
            {
                return 0;
            }

            if grid[i as usize][j as usize] == 2 {
                return if spaces == 0 { 1 } else { 0 };
            }

            let mut result = 0;

            grid[i as usize][j as usize] = -1;

            result += dfs(grid, i + 1, j, spaces - 1);
            result += dfs(grid, i - 1, j, spaces - 1);
            result += dfs(grid, i, j + 1, spaces - 1);
            result += dfs(grid, i, j - 1, spaces - 1);

            grid[i as usize][j as usize] = 0;

            result
        }

        let mut grid = grid;
        let mut start_x = -1;
        let mut start_y = -1;
        let mut spaces = 1;
        let row_size = grid.len();
        let col_size = grid[0].len();

        for i in 0..row_size {
            for j in 0..col_size {
                if grid[i][j] == 1 {
                    start_x = i as i32;
                    start_y = j as i32;
                } else if grid[i][j] == 0 {
                    spaces += 1;
                }
            }
        }

        dfs(&mut grid, start_x, start_y, spaces)
    }
}
