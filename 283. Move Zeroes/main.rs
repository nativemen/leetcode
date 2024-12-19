impl Solution {
    pub fn move_zeroes(nums: &mut Vec<i32>) {
        let count = nums.iter().filter(|&&x| x == 0).count();
        nums.retain(|&x| x != 0);
        nums.extend(std::iter::repeat(0).take(count));
    }
}

impl Solution {
    pub fn move_zeroes(nums: &mut Vec<i32>) {
        let mut non_zero_index = 0;

        for i in 0..nums.len() {
            if nums[i] != 0 {
                nums.swap(non_zero_index, i);
                non_zero_index += 1;
            }
        }
    }
}

impl Solution {
    pub fn move_zeroes(nums: &mut Vec<i32>) {
        let mut zero_pos = 0;

        for i in 0..nums.len() {
            if nums[i] != 0 {
                nums[zero_pos] = nums[i];
                zero_pos += 1;
            }
        }

        for i in zero_pos..nums.len() {
            nums[i] = 0;
        }
    }
}
