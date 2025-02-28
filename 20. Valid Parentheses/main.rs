use std::collections::HashMap;

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack = Vec::new();
        let valid = HashMap::from([('{', '}'), ('[', ']'), ('(', ')')]);

        for c in s.chars() {
            if valid.contains_key(&c) {
                stack.push(c);
            } else {
                if stack.is_empty() || c != valid[stack.last().unwrap()] {
                    return false;
                }
                stack.pop();
            }
        }

        stack.is_empty()
    }
}

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack = Vec::new();

        for c in s.chars() {
            match c {
                '{' | '[' | '(' => stack.push(c),
                '}' => {
                    if Some('{') != stack.pop() {
                        return false;
                    }
                }
                ']' => {
                    if Some('[') != stack.pop() {
                        return false;
                    }
                }
                ')' => {
                    if Some('(') != stack.pop() {
                        return false;
                    }
                }
                _ => (),
            }
        }

        stack.is_empty()
    }
}

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack = Vec::new();

        for c in s.chars() {
            match c {
                '{' => stack.push('}'),
                '[' => stack.push(']'),
                '(' => stack.push(')'),
                _ => {
                    if Some(c) != stack.pop() {
                        return false;
                    }
                }
            }
        }

        stack.is_empty()
    }
}

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut s = s.clone();
        let mut p = "".to_string();

        while s != p {
            p = s.clone();
            s = s.replace("{}", "").replace("[]", "").replace("()", "");
        }

        s.is_empty()
    }
}
