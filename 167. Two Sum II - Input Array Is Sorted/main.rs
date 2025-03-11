struct Solution;

impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let mut left = 0;
        let mut right = numbers.len() as i32 - 1;

        while left < right {
            let sum = numbers[left as usize] + numbers[right as usize];
            if sum < target {
                left += 1;
            } else if sum > target {
                right -= 1;
            } else {
                break;
            }
        }

        vec![left + 1, right + 1]
    }
}

impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        for first in 0..numbers.len() {
            let object = target - numbers[first];
            if let Ok(index) = numbers[first + 1..].binary_search(&object) {
                return vec![first as i32 + 1, index as i32 + first as i32 + 2];
            }
        }

        vec![-1, -1]
    }
}
