struct Solution;

impl Solution {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        let size = ratings.len();
        let mut candy = vec![1; size];

        for i in 1..size {
            if ratings[i] > ratings[i - 1] {
                candy[i] = candy[i - 1] + 1;
            }
        }

        let mut sum = candy[size - 1];

        for i in (0..size - 1).rev() {
            if ratings[i] > ratings[i + 1] {
                candy[i] = candy[i].max(candy[i + 1] + 1);
            }
            sum += candy[i];
        }

        sum
    }
}

impl Solution {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        let size = ratings.len();
        let mut candy = vec![1; size];

        for i in 1..size {
            if ratings[i] > ratings[i - 1] {
                candy[i] = candy[i - 1] + 1;
            }
        }

        for i in (0..size - 1).rev() {
            if ratings[i] > ratings[i + 1] {
                candy[i] = candy[i].max(candy[i + 1] + 1);
            }
        }

        candy.iter().sum()
    }
}
