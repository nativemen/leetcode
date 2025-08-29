struct Solution;

impl Solution {
    pub fn combination_sum3(k: i32, n: i32) -> Vec<Vec<i32>> {
        fn backtrace(result: &mut Vec<Vec<i32>>, array: &mut Vec<i32>, k: i32, n: i32, start: i32) {
            if k == 0 {
                if n == 0 {
                    result.push(array.clone());
                }

                return;
            }

            for i in start..=9 {
                if i > n {
                    break;
                }

                array.push(i);
                backtrace(result, array, k - 1, n - i, i + 1);
                array.pop();
            }
        }

        let mut result = Vec::new();
        let mut array = Vec::new();

        backtrace(&mut result, &mut array, k, n, 1);

        result
    }
}
