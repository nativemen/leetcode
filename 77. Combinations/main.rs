struct Solution;

impl Solution {
    pub fn combine(n: i32, k: i32) -> Vec<Vec<i32>> {
        let mut result = Vec::new();

        if n <= 0 || k <= 0 || k > n {
            return result;
        }

        let mut array = Vec::new();
        Self::backtrack(&mut result, &mut array, n, k, 1);

        result
    }

    fn backtrack(result: &mut Vec<Vec<i32>>, array: &mut Vec<i32>, n: i32, k: i32, value: i32) {
        if array.len() == k as usize {
            result.push(array.clone());
            return;
        }

        for i in value..=n {
            array.push(i);
            Self::backtrack(result, array, n, k, i + 1);
            array.pop();
        }
    }
}
