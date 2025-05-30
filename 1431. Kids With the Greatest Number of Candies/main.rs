struct Solution;

impl Solution {
    pub fn kids_with_candies(candies: Vec<i32>, extra_candies: i32) -> Vec<bool> {
        let max_candies = *candies.iter().max().unwrap();
        let mut result = Vec::new();

        for current in candies.into_iter() {
            result.push(current + extra_candies >= max_candies);
        }

        result
    }
}

impl Solution {
    pub fn kids_with_candies(candies: Vec<i32>, extra_candies: i32) -> Vec<bool> {
        let max_candies = *candies.iter().max().unwrap();

        candies
            .iter()
            .map(|current| current + extra_candies >= max_candies)
            .collect()
    }
}
