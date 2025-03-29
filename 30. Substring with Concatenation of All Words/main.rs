struct Solution;

impl Solution {
    pub fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        let s_len = s.len();
        let words_size = words.len();
        let word_len = words[0].len();
        let total = word_len * words_size;
        let mut result = Vec::new();

        if s_len < total {
            return result;
        }

        let mut checked = vec![0; words_size];
        let search_size = s_len - total;
        for i in 0..=search_size {
            let mut offset = i;
            let mut count = 0;
            let mut sub_str = &s[offset..offset + word_len];

            while !Self::is_all_matched(&checked) {
                let mut found = false;

                for j in 0..words_size {
                    if checked[j] == 1 {
                        continue;
                    }

                    if words[j].eq(sub_str) {
                        checked[j] = 1;
                        count += 1;
                        found = true;
                        offset += word_len;
                        if offset + word_len <= s_len {
                            sub_str = &s[offset..offset + word_len];
                        }
                    }
                }

                if !found {
                    break;
                }
            }

            if count == words_size {
                result.push(i as i32);
            }

            checked = vec![0; words_size];
        }

        result
    }

    fn is_all_matched(checked: &Vec<usize>) -> bool {
        for &item in checked.iter() {
            if item == 0 {
                return false;
            }
        }

        true
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        let s_len = s.len();
        let words_size = words.len();
        let word_len = words[0].len();
        let total = word_len * words_size;
        let mut result = Vec::new();

        if s_len < total {
            return result;
        }

        let mut maps1 = HashMap::new();
        for word in words.iter() {
            *maps1.entry(word.as_str()).or_insert(0) += 1;
        }

        let search_size = s_len - total;

        for i in 0..=search_size {
            let mut maps2 = maps1.clone();
            let mut offset = i;

            for j in 0..words_size {
                let sub_str = &s[offset..offset + word_len];

                match maps2.get_mut(sub_str) {
                    Some(count) => {
                        if *count == 0 {
                            break;
                        }

                        *count -= 1;
                    }
                    None => break,
                }

                if j == words_size - 1 {
                    result.push(i as i32);
                    break;
                }

                offset += word_len;
            }
        }

        result
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        let s_len = s.len();
        let words_size = words.len();
        let word_len = words[0].len();
        let total = word_len * words_size;
        let mut result = Vec::new();

        if s_len < total {
            return result;
        }

        let mut maps1 = HashMap::new();
        for word in words.iter() {
            *maps1.entry(word.as_str()).or_insert(0) += 1;
        }

        for i in 0..word_len {
            let mut start = i;
            let mut maps2 = HashMap::new();

            for end in (i..=s_len).step_by(word_len).skip(1) {
                let sub_str = &s[end - word_len..end];

                if let Some(&required_count) = maps1.get(sub_str) {
                    *maps2.entry(sub_str).or_insert(0) += 1;

                    while maps2[sub_str] > required_count {
                        let to_drop = &s[start..start + word_len];

                        *maps2.get_mut(to_drop).unwrap() -= 1;
                        start += word_len;
                    }

                    if end - start == total {
                        result.push(start as i32);
                    }
                } else {
                    start = end;
                    maps2 = HashMap::new();
                }
            }
        }

        result
    }
}

use std::collections::hash_map::DefaultHasher;
use std::hash::{Hash, Hasher};

impl Solution {
    pub fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        let s_len = s.len();
        let words_size = words.len();
        let word_len = words[0].len();
        let total = word_len * words_size;
        let mut result = Vec::new();

        if s_len < total {
            return result;
        }

        let mut target_hash = 0;
        for word in words.iter() {
            target_hash += Self::a_hash(&word);
        }

        for i in 0..word_len {
            let mut current_hash = 0;

            for j in 0..words_size {
                let offset = i + j * word_len;
                current_hash += Self::a_hash(&s[offset..offset + word_len].to_string());
            }

            if current_hash == target_hash {
                result.push(i as i32);
            }

            for j in (i + word_len..=s_len - total).step_by(word_len) {
                current_hash -= Self::a_hash(&s[j - word_len..j].to_string());
                current_hash += Self::a_hash(&s[j + total - word_len..j + total].to_string());

                if current_hash == target_hash {
                    result.push(j as i32);
                }
            }
        }

        result
    }

    fn a_hash<T: Hash>(value: &T) -> u64 {
        let mut hasher = DefaultHasher::new();
        value.hash(&mut hasher);
        hasher.finish()
    }
}
