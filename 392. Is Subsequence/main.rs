struct Solution;

impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        let mut ti = 0;
        let mut count = 0;

        for c1 in s.chars() {
            for c2 in t[ti..].chars() {
                ti += 1;
                if c1 == c2 {
                    count += 1;
                    break;
                }
            }
        }

        return count == s.len();
    }
}

impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        let mut sc = s.chars();
        let mut tc = t.chars();

        let mut current = match sc.next() {
            Some(c) => c,
            None => return true,
        };

        for ch in tc {
            if ch == current {
                current = match sc.next() {
                    Some(c) => c,
                    None => return true,
                };
            }
        }

        false
    }
}
