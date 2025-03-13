struct Solution;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        const ARRAY_SIZE: usize = 256;
        let mut count = vec![0; ARRAY_SIZE];
        let size = s.len();
        let mut left = 0;
        let mut result = 0;

        for right in 0..size {
            count[s[right]] += 1;

            while count[s[right]] > 1 {
                count[s[left]] -= 1;
                left += 1;
            }

            result = result.max(right - left + 1);
        }

        result
    }
}

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        const ARRAY_SIZE: usize = 256;
        let mut count = vec![0; ARRAY_SIZE];
        let size = s.len();
        let mut left = 0;
        let mut result = 0;

        for (right, c) in s.chars().enumerate() {
            count[c as usize] += 1;

            while count[c as usize] > 1 {
                count[s.chars().nth(left).unwrap() as usize] -= 1;
                left += 1;
            }

            result = result.max(right as i32 - left as i32 + 1);
        }

        result
    }
}

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut result = 0;
        let mut left = 0;

        for (right, rc) in s.chars().enumerate() {
            for (start, sc) in s[left..right].chars().enumerate() {
                if rc == sc {
                    left += start + 1;
                    break;
                }
            }

            result = result.max(right - left + 1);
        }

        result as i32
    }
}

use std::collections::HashSet;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut set = HashSet::new();
        let mut result = 0;
        let mut left = 0;

        for (right, rc) in s.chars().enumerate() {
            while set.contains(&rc) {
                set.remove(&s.chars().nth(left).unwrap());
                left += 1;
            }
            set.insert(rc);
            result = result.max(right - left + 1);
        }

        result as i32
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut map = HashMap::new();
        let mut result = 0;
        let mut left = 0;

        for (right, rc) in s.chars().enumerate() {
            if let Some(index) = map.get(&rc) {
                left = index + 1;
            }
            map.insert(rc, right);
            result = result.max(right - left + 1);
        }

        result as i32
    }
}
