struct Solution;

impl Solution {
    pub fn find_different_binary_string(nums: Vec<String>) -> String {
        let size = nums.len();
        let mut exists = vec![false; 1 << size];

        for num in nums.iter() {
            if let Ok(value) = i32::from_str_radix(num, 2) {
                exists[value as usize] = true;
            }
        }

        let mut val = 0;
        while val < 1 << size {
            if !exists[val] {
                break;
            }
            val += 1;
        }

        format!("{val:0size$b}")
    }
}

impl Solution {
    pub fn find_different_binary_string(nums: Vec<String>) -> String {
        let mut res = String::new();

        for i in 0..nums.len() {
            if nums[i].chars().nth(i) == Some('0') {
                res.push('1');
            } else {
                res.push('0');
            }
        }

        res
    }
}
