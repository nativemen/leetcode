struct Solution;

impl Solution {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        let mut obstacle_grid = obstacle_grid;
        let row_size = obstacle_grid.len();
        let col_size = obstacle_grid[0].len();

        obstacle_grid[0][0] = if obstacle_grid[0][0] == 1 { 0 } else { 1 };

        for i in 1..row_size {
            obstacle_grid[i][0] = if obstacle_grid[i][0] == 1 {
                0
            } else {
                obstacle_grid[i - 1][0]
            };
        }

        for j in 1..col_size {
            obstacle_grid[0][j] = if obstacle_grid[0][j] == 1 {
                0
            } else {
                obstacle_grid[0][j - 1]
            };
        }

        for i in 1..row_size {
            for j in 1..col_size {
                obstacle_grid[i][j] = if obstacle_grid[i][j] == 1 {
                    0
                } else {
                    obstacle_grid[i - 1][j] + obstacle_grid[i][j - 1]
                };
            }
        }

        obstacle_grid[row_size - 1][col_size - 1]
    }
}
