struct Solution;

impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {
        let mut triangle = vec![vec![1]];

        for i in 1..=row_index as usize {
            let mut row = vec![1; i + 1];
            for j in 1..i {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push(row);
        }

        triangle[row_index as usize].clone()
    }
}

impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {
        let mut triangle = vec![vec![1]];

        for i in 1..=row_index as usize {
            triangle.push(vec![1; i + 1]);
            for j in 1..i {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }

        triangle[row_index as usize].clone()
    }
}

impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {
        let mut row = vec![1i32; row_index as usize + 1];
        let mut val = 1i64;

        for i in 0..=row_index as usize {
            row[i] = val as i32;
            val = val * (row_index as i64 - i as i64) / (i as i64 + 1);
        }

        row
    }
}
