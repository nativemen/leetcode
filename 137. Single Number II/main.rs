struct Solution;

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut nums = nums;

        nums.sort();

        for i in (1..nums.len()).step_by(3) {
            if nums[i] != nums[i - 1] {
                return nums[i - 1];
            }
        }

        nums.last().unwrap().to_owned()
    }
}

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut nums = nums;

        nums.sort();

        let mut index = 0;
        let size = nums.len();

        while index < size - 1 {
            if nums[index] != nums[index + 1] {
                return nums[index];
            }

            index += 3;
        }

        nums.last().unwrap().to_owned()
    }
}

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut ones = 0;
        let mut twos = 0;

        for num in nums {
            twos |= ones & num;
            ones ^= num;

            let mask = !(ones & twos);
            ones &= mask;
            twos &= mask;
        }

        ones
    }
}

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut ones = 0;
        let mut twos = 0;

        for num in nums {
            ones ^= num & !twos;
            twos ^= num & !ones;
        }

        ones
    }
}

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut ones = 0;
        let mut multi = 0;

        for num in nums {
            ones = (ones ^ num) & !multi;
            multi = (multi ^ num) & !ones;
        }

        ones
    }
}

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut result = 0;

        for i in 0..32 {
            let mask = 1 << i;
            let mut count = 0;

            for &num in nums.iter() {
                if num & mask != 0 {
                    count += 1;
                }
            }

            if count % 3 != 0 {
                result |= mask;
            }
        }

        result
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut hashmap = HashMap::new();

        for num in nums {
            hashmap
                .entry(num)
                .and_modify(|count| *count += 1)
                .or_insert(1);
        }

        for (key, value) in hashmap {
            if value == 1 {
                return key;
            }
        }

        -1
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut hashmap = HashMap::new();

        for num in nums {
            *hashmap.entry(num).or_insert(0) += 1;
        }

        for (&key, &value) in &hashmap {
            if value == 1 {
                return key;
            }
        }

        -1
    }
}
