struct Solution;

impl Solution {
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        let mut result = vec![vec![0; n as usize]; n as usize];
        let mut left = 0;
        let mut right = n - 1;
        let mut top = 0;
        let mut bottom = n - 1;
        let mut num = 1;

        while left <= right && top <= bottom {
            for i in left..=right {
                result[top as usize][i as usize] = num;
                num += 1;
            }
            top += 1;

            for i in top..=bottom {
                result[i as usize][right as usize] = num;
                num += 1;
            }
            right -= 1;

            if top <= bottom {
                for i in (left..=right).rev() {
                    result[bottom as usize][i as usize] = num;
                    num += 1;
                }
                bottom -= 1;
            }

            if left <= right {
                for i in (top..=bottom).rev() {
                    result[i as usize][left as usize] = num;
                    num += 1;
                }
                left += 1;
            }
        }

        result
    }
}

impl Solution {
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        let mut result = vec![vec![0; n as usize]; n as usize];
        let mut left = 0;
        let mut right = n - 1;
        let mut top = 0;
        let mut bottom = n - 1;
        let mut num = 1;
        let total = n * n;

        while num <= total {
            for i in left..=right {
                result[top as usize][i as usize] = num;
                num += 1;
            }
            top += 1;

            for i in top..=bottom {
                result[i as usize][right as usize] = num;
                num += 1;
            }
            right -= 1;

            for i in (left..=right).rev() {
                result[bottom as usize][i as usize] = num;
                num += 1;
            }
            bottom -= 1;

            for i in (top..=bottom).rev() {
                result[i as usize][left as usize] = num;
                num += 1;
            }
            left += 1;
        }

        result
    }
}

impl Solution {
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        let mut result = vec![vec![0; n as usize]; n as usize];
        let mut left = 0;
        let mut right = n - 1;
        let mut top = 0;
        let mut bottom = n - 1;
        let mut num = 1;
        let total = n * n;
        let mut direction = 1;

        while num <= total {
            match direction {
                1 => {
                    for i in left..=right {
                        result[top as usize][i as usize] = num;
                        num += 1;
                    }
                    top += 1;
                    direction = 2;
                }
                2 => {
                    for i in top..=bottom {
                        result[i as usize][right as usize] = num;
                        num += 1;
                    }
                    right -= 1;
                    direction = 3;
                }
                3 => {
                    for i in (left..=right).rev() {
                        result[bottom as usize][i as usize] = num;
                        num += 1;
                    }
                    bottom -= 1;
                    direction = 4;
                }
                _ => {
                    for i in (top..=bottom).rev() {
                        result[i as usize][left as usize] = num;
                        num += 1;
                    }
                    left += 1;
                    direction = 1;
                }
            }
        }

        result
    }
}
