struct Solution;

impl Solution {
    pub fn reverse_words(s: String) -> String {
        let mut words = Vec::new();
        let mut word = String::new();

        for c in s.chars() {
            if c != ' ' {
                word.push(c);
            } else {
                if !word.is_empty() {
                    words.push(word.clone());
                    word.clear();
                }
            }
        }

        if !word.is_empty() {
            words.push(word);
        }

        let mut result = String::new();
        for word in words.iter().rev() {
            if !result.is_empty() {
                result.push(' ');
            }
            result.push_str(word);
        }

        result
    }
}

impl Solution {
    pub fn reverse_words(s: String) -> String {
        let mut words = Vec::new();
        let mut word = String::new();

        for c in s.chars().rev() {
            if c != ' ' {
                word.insert(0, c);
            } else {
                if !word.is_empty() {
                    words.push(word.clone());
                    word.clear();
                }
            }
        }

        if !word.is_empty() {
            words.push(word);
        }

        words.join(" ")
    }
}

impl Solution {
    pub fn reverse_words(s: String) -> String {
        s.split_ascii_whitespace()
            .rev()
            .collect::<Vec<_>>()
            .join(" ")
    }
}

impl Solution {
    pub fn reverse_words(s: String) -> String {
        let mut result = String::new();
        let mut count = 0;
        let mut start = 0;
        let size = s.len();

        for i in (0..size).rev() {
            if s.chars().nth(i) != Some(' ') {
                count += 1;
                if i == 0 || s.chars().nth(i - 1).unwrap() == ' ' {
                    result.push_str(&s[i..i + count]);
                    result.push(' ');
                    count = 0
                }
            }
        }

        result.trim_end().to_string()
    }
}
