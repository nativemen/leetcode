impl Solution {
    pub fn first_uniq_char(s: String) -> i32 {
        for (i, c) in s.chars().enumerate() {
            if s.find(c) == s.rfind(c) {
                return i as i32;
            }
        }

        -1
    }
}

impl Solution {
    pub fn first_uniq_char(s: String) -> i32 {
        let chars: Vec<char> = s.chars().collect();
        for (i, &c) in chars.iter().enumerate() {
            if chars.iter().position(|&x| x == c) == chars.iter().rposition(|&x| x == c) {
                return i as i32;
            }
        }

        -1
    }
}

const ARRAY_SIZE: usize = 26;

impl Solution {
    pub fn first_uniq_char(s: String) -> i32 {
        let mut count = [0; ARRAY_SIZE];

        for c in s.chars() {
            count[(c as u8 - b'a') as usize] += 1;
        }

        for (i, c) in s.chars().enumerate() {
            if count[(c as u8 - b'a') as usize] == 1 {
                return i as i32;
            }
        }

        -1
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn first_uniq_char(s: String) -> i32 {
        let mut map: HashMap<char, i32> = HashMap::new();

        for c in s.chars() {
            map.entry(c).and_modify(|val| *val += 1).or_insert(1);
        }

        for (i, c) in s.chars().enumerate() {
            if let Some(1) = map.get(&c) {
                return i as i32;
            }
        }

        -1
    }
}