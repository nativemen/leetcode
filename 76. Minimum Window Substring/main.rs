struct Solution;

use std::collections::HashMap;

impl Solution {
    pub fn min_window(s: String, t: String) -> String {
        let s_vec = s.chars().collect::<Vec<_>>();
        let t_vec = t.chars().collect::<Vec<_>>();
        let mut t_map = HashMap::new();

        for &c in t_vec.iter() {
            *t_map.entry(c).or_insert(0) += 1;
        }

        let t_len = t.len();
        let mut left = 0;
        let mut matched = 0;
        let mut min_len = usize::MAX;
        let mut min_left = 0;
        let mut s_map = HashMap::new();

        for (right, &c) in s_vec.iter().enumerate() {
            if !t_map.contains_key(&c) {
                continue;
            }

            *s_map.entry(c).or_insert(0) += 1;

            if s_map[&c] <= t_map[&c] {
                matched += 1;
            }

            if matched == t_len {
                while !t_map.contains_key(&s_vec[left]) || s_map[&s_vec[left]] > t_map[&s_vec[left]]
                {
                    if t_map.contains_key(&s_vec[left]) {
                        *s_map.get_mut(&s_vec[left]).unwrap() -= 1;
                    }

                    left += 1;
                }

                let size = right - left + 1;

                if size < min_len {
                    min_len = size;
                    min_left = left;
                }
            }
        }

        if min_len == usize::MAX {
            return "".to_string();
        }

        s[min_left..min_left + min_len].into()
    }
}

impl Solution {
    pub fn min_window(s: String, t: String) -> String {
        let s_vec = s.chars().collect::<Vec<_>>();
        let t_vec = t.chars().collect::<Vec<_>>();
        const ARRAY_SIZE: usize = 128;
        let mut count = vec![0; ARRAY_SIZE];

        for &c in t_vec.iter() {
            count[c as usize] += 1;
        }

        let s_len = s_vec.len();
        let t_len = t_vec.len();
        let mut right = 0;
        let mut left = 0;
        let mut needed = t_len;
        let mut min_len = usize::MAX;
        let mut min_left = 0;

        while left < s_len {
            if right >= s_len && needed > 0 {
                break;
            }

            if needed > 0 {
                if count[s_vec[right] as usize] > 0 {
                    needed -= 1;
                }
                count[s_vec[right] as usize] -= 1;
                right += 1;
            } else {
                let size = right - left;
                if size < min_len {
                    min_len = size;
                    min_left = left;
                }

                count[s_vec[left] as usize] += 1;
                if count[s_vec[left] as usize] > 0 {
                    needed += 1;
                }
                left += 1;
            }
        }

        if min_len == usize::MAX {
            return "".to_string();
        }

        s[min_left..min_left + min_len].into()
    }
}

impl Solution {
    pub fn min_window(s: String, t: String) -> String {
        let s_bytes = s.as_bytes();
        let t_bytes = t.as_bytes();
        const ARRAY_SIZE: usize = 128;
        let mut count = vec![0; ARRAY_SIZE];

        for &c in t_bytes {
            count[c as usize] += 1;
        }

        let s_len = s_bytes.len();
        let t_len = t_bytes.len();
        let mut right = 0;
        let mut left = 0;
        let mut needed = t_len;
        let mut min_len = usize::MAX;
        let mut min_left = 0;

        while left < s_len {
            if right >= s_len && needed > 0 {
                break;
            }

            if needed > 0 {
                if count[s_bytes[right] as usize] > 0 {
                    needed -= 1;
                }
                count[s_bytes[right] as usize] -= 1;
                right += 1;
            } else {
                let size = right - left;
                if size < min_len {
                    min_len = size;
                    min_left = left;
                }

                count[s_bytes[left] as usize] += 1;
                if count[s_bytes[left] as usize] > 0 {
                    needed += 1;
                }
                left += 1;
            }
        }

        if min_len == usize::MAX {
            return "".to_string();
        }

        s[min_left..min_left + min_len].into()
    }
}


impl Solution {
    pub fn min_window(s: String, t: String) -> String {
        let s_bytes = s.as_bytes();
        let t_bytes = t.as_bytes();
        const ARRAY_SIZE: usize = 128;
        let mut count = vec![0; ARRAY_SIZE];

        for &c in t_bytes {
            count[c as usize] += 1;
        }

        let s_len = s_bytes.len();
        let t_len = t_bytes.len();
        let mut left = 0;
        let mut matched = 0;
        let mut min_len = usize::MAX;
        let mut min_left = 0;

        for right in 0..s_len {
            if count[s_bytes[right] as usize] > 0 {
                matched += 1;
            }

            count[s_bytes[right] as usize] -= 1;

            while matched == t_len {
                let size = right - left + 1;

                if size < min_len {
                    min_len = size;
                    min_left = left;
                }

                count[s_bytes[left] as usize] += 1;

                if count[s_bytes[left] as usize] > 0 {
                    matched -= 1;
                }
                left += 1;
            }
        }

        if min_len == usize::MAX {
            return "".to_string();
        }

        s[min_left..min_left + min_len].into()
    }
}
