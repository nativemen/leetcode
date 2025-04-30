struct Solution;

impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let row_size = matrix.len() as i32;
        if row_size <= 0 {
            return false;
        }

        let col_size = matrix[0].len() as i32;
        if col_size <= 0 {
            return false;
        }

        let mut left = 0;
        let mut right = row_size * col_size - 1;

        while left <= right {
            let mid = (left + right) / 2;
            let row = (mid / col_size) as usize;
            let col = (mid % col_size) as usize;

            if target < matrix[row][col] {
                right = mid - 1;
            } else if target > matrix[row][col] {
                left = mid + 1;
            } else {
                return true;
            }
        }

        false
    }
}
