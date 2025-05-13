struct Solution;

impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result = Vec::new();

        if nums.is_empty() {
            return result;
        }

        let mut array = Vec::new();
        let mut visited = vec![false; nums.len()];

        Self::backtrack(&nums, &mut result, &mut array, &mut visited);

        result
    }

    fn backtrack(
        nums: &Vec<i32>,
        result: &mut Vec<Vec<i32>>,
        array: &mut Vec<i32>,
        visited: &mut Vec<bool>,
    ) {
        if array.len() == nums.len() {
            result.push(array.clone());
            return;
        }

        for i in 0..nums.len() {
            if visited[i] {
                continue;
            }

            visited[i] = true;
            array.push(nums[i]);
            Self::backtrack(nums, result, array, visited);
            array.pop();
            visited[i] = false;
        }
    }
}

impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result = Vec::new();

        if nums.is_empty() {
            return result;
        }

        let mut array = Vec::new();

        Self::backtrack(&nums, &mut result, &mut array);

        result
    }

    fn backtrack(nums: &Vec<i32>, result: &mut Vec<Vec<i32>>, array: &mut Vec<i32>) {
        if array.len() == nums.len() {
            result.push(array.clone());
            return;
        }

        for i in 0..nums.len() {
            if array.contains(&nums[i]) {
                continue;
            }

            array.push(nums[i]);
            Self::backtrack(nums, result, array);
            array.pop();
        }
    }
}

impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result = Vec::new();

        if nums.is_empty() {
            return result;
        }

        let mut nums = nums;

        Self::backtrack(&mut nums, &mut result, 0);

        result
    }

    fn backtrack(nums: &mut Vec<i32>, result: &mut Vec<Vec<i32>>, depth: usize) {
        if depth == nums.len() {
            result.push(nums.clone());
            return;
        }

        for i in depth..nums.len() {
            nums.swap(i, depth);
            Self::backtrack(nums, result, depth + 1);
            nums.swap(i, depth);
        }
    }
}
