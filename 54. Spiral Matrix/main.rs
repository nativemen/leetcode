struct Solution;

impl Solution {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let row_num = matrix.len();
        let col_num = matrix[0].len();
        let mut left = 0;
        let mut right = col_num as i32 - 1;
        let mut top = 0;
        let mut bottom = row_num as i32 - 1;
        let mut result = Vec::new();

        while left <= right && top <= bottom {
            for i in left..=right {
                result.push(matrix[top as usize][i as usize]);
            }
            top += 1;

            for i in top..=bottom {
                result.push(matrix[i as usize][right as usize]);
            }
            right -= 1;

            if top <= bottom {
                for i in (left..=right).rev() {
                    result.push(matrix[bottom as usize][i as usize]);
                }
                bottom -= 1;
            }

            if left <= right {
                for i in (top..=bottom).rev() {
                    result.push(matrix[i as usize][left as usize]);
                }
                left += 1;
            }
        }

        result
    }
}

impl Solution {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let row_num = matrix.len();
        let col_num = matrix[0].len();
        let mut left = 0;
        let mut right = col_num as i32 - 1;
        let mut top = 0;
        let mut bottom = row_num as i32 - 1;
        let mut direction = 1;
        let mut result = Vec::new();

        while result.len() < row_num * col_num {
            match direction {
                1 => {
                    for i in left..=right {
                        result.push(matrix[top as usize][i as usize]);
                    }
                    top += 1;
                    direction = 2;
                }
                2 => {
                    for i in top..=bottom {
                        result.push(matrix[i as usize][right as usize]);
                    }
                    right -= 1;
                    direction = 3;
                }
                3 => {
                    for i in (left..=right).rev() {
                        result.push(matrix[bottom as usize][i as usize]);
                    }
                    bottom -= 1;
                    direction = 4;
                }
                _ => {
                    for i in (top..=bottom).rev() {
                        result.push(matrix[i as usize][left as usize]);
                    }
                    left += 1;
                    direction = 1;
                }
            }
        }

        result
    }
}
