struct Solution;

use std::collections::VecDeque;

impl Solution {
    pub fn nearest_exit(maze: Vec<Vec<char>>, entrance: Vec<i32>) -> i32 {
        let mut maze = maze;
        let mut q = VecDeque::new();

        q.push_back((entrance[0] as usize, entrance[1] as usize));
        maze[entrance[0] as usize][entrance[1] as usize] = '*';

        let mut count = 0;
        let row_size = maze.len();
        let col_size = maze[0].len();

        while !q.is_empty() {
            let size = q.len();

            for _ in 0..size {
                if let Some((x, y)) = q.pop_front() {
                    if count > 0 && (x == 0 || x == row_size - 1 || y == 0 || y == col_size - 1) {
                        return count;
                    }

                    if x > 0 && maze[x - 1][y] == '.' {
                        q.push_back((x - 1, y));
                        maze[x - 1][y] = '*';
                    }

                    if x < row_size - 1 && maze[x + 1][y] == '.' {
                        q.push_back((x + 1, y));
                        maze[x + 1][y] = '*';
                    }

                    if y > 0 && maze[x][y - 1] == '.' {
                        q.push_back((x, y - 1));
                        maze[x][y - 1] = '*';
                    }

                    if y < col_size - 1 && maze[x][y + 1] == '.' {
                        q.push_back((x, y + 1));
                        maze[x][y + 1] = '*';
                    }
                }
            }

            count += 1;
        }

        -1
    }
}
