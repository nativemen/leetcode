impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut count = 1;
        let mut repeat = 0;
        let mut prev = nums[0];
        let size = nums.len();

        for i in 1..size {
            if (nums[i] == prev) {
                repeat += 1;
            } else {
                repeat = 0;
                prev = nums[i];
            }

            if (repeat <= 1) {
                nums[count] = nums[i];
                count += 1;
            }
        }

        count as i32
    }
}

impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let size = nums.len();

        if size <= 2 {
            return size as i32;
        }

        let mut count = 2;

        for i in 2..size {
            if nums[i] != nums[count - 2] {
                nums[count] = nums[i];
                count += 1;
            }
        }

        count as i32
    }
}
