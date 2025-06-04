struct Solution;

impl Solution {
    pub fn remove_stars(s: String) -> String {
        let mut result = Vec::new();

        for c in s.chars() {
            if c == '*' {
                result.pop();
            } else {
                result.push(c);
            }
        }

        result.iter().collect::<String>()
    }
}

impl Solution {
    pub fn remove_stars(s: String) -> String {
        let mut result = Vec::new();

        for c in s.chars() {
            if c == '*' {
                result.pop();
            } else {
                result.push(c);
            }
        }

        result.into_iter().collect()
    }
}
