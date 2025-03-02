struct Solution;

const ARRAY_SIZE: usize = 2001;

impl Solution {
    pub fn find_kth_positive(arr: Vec<i32>, k: i32) -> i32 {
        let mut is_missing = vec![true; ARRAY_SIZE];

        for num in arr {
            is_missing[num as usize] = false;
        }

        let mut k = k;
        for i in 1..ARRAY_SIZE {
            if !is_missing[i] {
                continue;
            }

            k -= 1;
            if k <= 0 {
                return i as i32;
            }
        }

        return -1;
    }
}

impl Solution {
    pub fn find_kth_positive(arr: Vec<i32>, k: i32) -> i32 {
        let mut left = 0;
        let mut right = arr.len() as i32 - 1;

        while left <= right {
            let mid = (left + right) / 2;
            if arr[mid as usize] - (mid + 1) < k {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        left + k
    }
}

impl Solution {
    pub fn find_kth_positive(arr: Vec<i32>, k: i32) -> i32 {
        let mut k = k;

        for num in arr {
            if num <= k {
                k += 1;
            }
        }

        k
    }
}
