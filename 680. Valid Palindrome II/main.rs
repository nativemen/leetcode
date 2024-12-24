struct Solution;

impl Solution {
    pub fn valid_palindrome(s: String) -> bool {
        let chars = s.chars().collect::<Vec<_>>();
        let mut left = 0;
        let mut right = chars.len() - 1;

        while left < right {
            if chars[left] != chars[right] {
                let skip_r = chars[left + 1..right + 1].into_iter().collect::<Vec<_>>();
                let skip_l = chars[left..right].into_iter().collect::<Vec<_>>();
                let rev_r = skip_r.clone().into_iter().rev().collect::<Vec<_>>();
                let rev_l = skip_l.clone().into_iter().rev().collect::<Vec<_>>();
                return skip_r.eq(&rev_r) || skip_l.eq(&rev_l);
            }

            left += 1;
            right -= 1;
        }

        true
    }
}

impl Solution {
    pub fn valid_palindrome(s: String) -> bool {
        let chars = s.chars().collect::<Vec<_>>();
        let mut left = 0;
        let mut right = chars.len() - 1;

        while left < right {
            if chars[left] != chars[right] {
                return Solution::is_equal(&chars, left + 1, right)
                    || Solution::is_equal(&chars, left, right - 1);
            }

            left += 1;
            right -= 1;
        }

        true
    }

    pub fn is_equal(chars: &Vec<char>, mut left: usize, mut right: usize) -> bool {
        while left < right {
            if chars[left] != chars[right] {
                return false;
            }

            left += 1;
            right -= 1;
        }

        true
    }
}

impl Solution {
    pub fn valid_palindrome(s: String) -> bool {
        let chars = s.chars().collect::<Vec<_>>();
        return Solution::is_equal(&chars, 0, chars.len() - 1, false);
    }

    pub fn is_equal(chars: &Vec<char>, mut left: usize, mut right: usize, skipped: bool) -> bool {
        while left < right {
            if chars[left] != chars[right] {
                if skipped {
                    return false;
                }
                return Solution::is_equal(chars, left + 1, right, true)
                    || Solution::is_equal(chars, left, right - 1, true);
            }

            left += 1;
            right -= 1;
        }

        true
    }
}

impl Solution {
    pub fn valid_palindrome(s: String) -> bool {
        let chars = s.chars().collect::<Vec<_>>();
        return Solution::is_equal(&chars, 0, chars.len() - 1, false);
    }

    pub fn is_equal(chars: &Vec<char>, mut left: usize, mut right: usize, skipped: bool) -> bool {
        if left >= right {
            return true;
        }

        if chars[left] != chars[right] {
            if skipped {
                return false;
            }
            return Solution::is_equal(chars, left + 1, right, true)
                || Solution::is_equal(chars, left, right - 1, true);
        }

        return Solution::is_equal(chars, left + 1, right - 1, skipped);
    }
}
