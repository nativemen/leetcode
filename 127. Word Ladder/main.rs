struct Solution;

use std::collections::HashSet;
use std::collections::VecDeque;

impl Solution {
    pub fn ladder_length(begin_word: String, end_word: String, word_list: Vec<String>) -> i32 {
        fn word_to_hash(word: &str) -> u64 {
            let mut hash = 0;

            for (i, c) in word.chars().enumerate() {
                hash = (hash << 5) | (c as u64 - 'a' as u64);
            }

            hash
        }

        fn gen_word_trans(word_hash: u64, word_len: usize) -> Vec<u64> {
            let mut word_trans = Vec::new();

            for i in 0..word_len {
                let mask = 0x1F << (i * 5);

                for val in 0..=26 {
                    let trans_hash = (word_hash & !mask) | (val << (i * 5));

                    if trans_hash != word_hash {
                        word_trans.push(trans_hash);
                    }
                }
            }

            word_trans
        }

        let mut word_hash_set: HashSet<u64> =
            HashSet::from_iter(word_list.iter().map(|word| word_to_hash(word)));
        let end_word_hash = word_to_hash(&end_word);

        if !word_hash_set.contains(&end_word_hash) {
            return 0;
        }

        let mut q = VecDeque::new();
        q.push_back((word_to_hash(&begin_word), 1));

        let word_len = begin_word.len();

        while !q.is_empty() {
            if let Some((current_hash, steps)) = q.pop_front() {
                if current_hash == end_word_hash {
                    return steps;
                }

                let word_trans = gen_word_trans(current_hash, word_len);

                for word_hash in word_trans.into_iter() {
                    if word_hash_set.contains(&word_hash) {
                        q.push_back((word_hash, steps + 1));
                        word_hash_set.remove(&word_hash);
                    }
                }
            }
        }

        0
    }
}

use std::collections::VecDeque;

impl Solution {
    pub fn ladder_length(begin_word: String, end_word: String, word_list: Vec<String>) -> i32 {
        fn is_valid(s1: &str, s2: &str) -> bool {
            if s1.len() != s2.len() {
                return false;
            }

            s1.chars()
                .zip(s2.chars())
                .filter(|(c1, c2)| c1.ne(c2))
                .count()
                == 1
        }

        if !word_list.contains(&end_word) {
            return 0;
        }

        let mut q = VecDeque::new();
        q.push_back((begin_word, 1));

        let list_len = word_list.len();
        let mut visited = vec![false; list_len];

        while !q.is_empty() {
            if let Some((current_word, steps)) = q.pop_front() {
                if current_word == end_word {
                    return steps;
                }

                for i in 0..list_len {
                    if !visited[i] && is_valid(&current_word, &word_list[i]) {
                        q.push_back((word_list[i].clone(), steps + 1));
                        visited[i] = true;
                    }
                }
            }
        }

        0
    }
}

use std::collections::HashSet;
use std::collections::VecDeque;

impl Solution {
    pub fn ladder_length(begin_word: String, end_word: String, word_list: Vec<String>) -> i32 {
        let mut word_list_set: HashSet<String> = HashSet::from_iter(word_list);

        if !word_list_set.contains(&end_word) {
            return 0;
        }

        let mut q = VecDeque::new();
        q.push_back((begin_word, 1));

        while !q.is_empty() {
            if let Some((current_word, steps)) = q.pop_front() {
                if current_word == end_word {
                    return steps;
                }

                for (i, ch) in current_word.chars().enumerate() {
                    for c in 'a'..='z' {
                        if c == ch {
                            continue;
                        }

                        let mut chars = current_word.chars().collect::<Vec<_>>();
                        chars[i] = c;
                        let word = String::from_iter(chars);

                        if word_list_set.contains(&word) {
                            word_list_set.remove(&word);
                            q.push_back((word, steps + 1));
                        }
                    }
                }
            }
        }

        0
    }
}
