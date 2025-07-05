struct Solution;

use std::collections::VecDeque;

impl Solution {
    pub fn oranges_rotting(grid: Vec<Vec<i32>>) -> i32 {
        let mut grid = grid;
        let mut q = VecDeque::new();
        let mut fresh = 0;
        let row_size = grid.len();
        let col_size = grid[0].len();

        for i in 0..row_size {
            for j in 0..col_size {
                if grid[i][j] == 1 {
                    fresh += 1;
                } else if grid[i][j] == 2 {
                    q.push_back((i, j));
                }
            }
        }

        if fresh == 0 {
            return 0;
        }

        let mut minutes = -1;

        while !q.is_empty() {
            let size = q.len();

            for _ in 0..size {
                if let Some((x, y)) = q.pop_front() {
                    if x > 0 && grid[x - 1][y] == 1 {
                        grid[x - 1][y] = 2;
                        q.push_back((x - 1, y));
                        fresh -= 1;
                    }

                    if x < row_size - 1 && grid[x + 1][y] == 1 {
                        grid[x + 1][y] = 2;
                        q.push_back((x + 1, y));
                        fresh -= 1;
                    }

                    if y > 0 && grid[x][y - 1] == 1 {
                        grid[x][y - 1] = 2;
                        q.push_back((x, y - 1));
                        fresh -= 1;
                    }

                    if y < col_size - 1 && grid[x][y + 1] == 1 {
                        grid[x][y + 1] = 2;
                        q.push_back((x, y + 1));
                        fresh -= 1;
                    }
                }
            }

            minutes += 1;
        }

        if fresh > 0 {
            return -1;
        }

        minutes
    }
}
