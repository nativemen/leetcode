use std::collections::HashMap;

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut hashmap = HashMap::new();
        for num in nums {
            let item = hashmap.entry(num).or_insert(0);
            *item += 1;
        }

        for (key, val) in hashmap {
            if val == 1 {
                return key;
            }
        }

        unreachable!()
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut hashmap = HashMap::new();
        for num in nums {
            let item = hashmap.entry(num).or_insert(0);
            if *item > 0 {
                hashmap.remove(&num);
            } else {
                *item += 1;
            }
        }

        if let Some((&key, &val)) = hashmap.iter().next() {
            return key;
        }

        unreachable!()
    }
}

use std::collections::HashSet;

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut hashset = HashSet::new();
        for num in nums {
            if !hashset.insert(num) {
                hashset.remove(&num);
            }
        }

        if let Some(&item) = hashset.iter().next() {
            return item;
        }

        unreachable!()
    }
}

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut answer = 0;
        for num in nums {
            answer ^= num;
        }

        answer
    }
}

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        nums.iter().fold(0, |acc, &x| acc ^ x)
    }
}
