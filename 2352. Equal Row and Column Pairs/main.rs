struct Solution;

impl Solution {
    pub fn equal_pairs(grid: Vec<Vec<i32>>) -> i32 {
        let row_size = grid.len();
        let col_size = grid[0].len();
        let mut count = 0;

        for c in 0..col_size {
            let mut column = Vec::new();

            for r in 0..row_size {
                column.push(grid[r][c]);
            }

            for r in 0..row_size {
                if column.eq(&grid[r]) {
                    count += 1;
                }
            }
        }

        count
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn equal_pairs(grid: Vec<Vec<i32>>) -> i32 {
        let row_size = grid.len();
        let col_size = grid[0].len();
        let mut maps = HashMap::new();

        for r in 0..row_size {
            maps.entry(grid[r].to_vec())
                .and_modify(|count| *count += 1)
                .or_insert(1);
        }

        let mut count = 0;

        for c in 0..col_size {
            let mut col = Vec::new();

            for r in 0..row_size {
                col.push(grid[r][c]);
            }

            if maps.contains_key(&col) {
                count += maps[&col];
            }
        }

        count
    }
}
