impl Solution {
    pub fn reverse_string(s: &mut Vec<char>) {
        s.rev();
    }
}

impl Solution {
    pub fn reverse_string(s: &mut Vec<char>) {
        *s = s.iter().cloned().rev().collect();
    }
}

impl Solution {
    pub fn reverse_string(s: &mut Vec<char>) {
        let mut left = 0;
        let mut right = s.len() - 1;

        while left < right {
            let temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left += 1;
            right -= 1;
        }
    }
}

impl Solution {
    pub fn reverse_string(s: &mut Vec<char>) {
        let mut stack = Vec::new();

        s.iter().for_each(|&c| stack.push(c));

        s.clear();
        for _ in 0..stack.len() {
            s.push(stack.pop().unwrap());
        }
    }
}

impl Solution {
    pub fn reverse_string(s: &mut Vec<char>) {
        for i in 0..s.len() / 2 {
            s.swap(i, len - 1 - i);
        }
    }
}
