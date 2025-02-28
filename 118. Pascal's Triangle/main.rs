struct Solution;

impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut triangle: Vec<Vec<i32>> = vec![vec![1]];

        for i in 1..num_rows as usize {
            let mut row = vec![1; i + 1];
            for j in 1..i {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push(row);
        }

        triangle
    }
}

impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut triangle: Vec<Vec<i32>> = vec![vec![1]];

        for i in 1..num_rows as usize {
            triangle.push(vec![1; i + 1]);
            for j in 1..i {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }

        triangle
    }
}
