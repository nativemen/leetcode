struct Solution;

impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {
            return false;
        }

        if x == 0 {
            return true;
        }

        let mut digit = Vec::new();
        let mut num = x;

        while num != 0 {
            digit.push(num % 10);
            num /= 10;
        }

        let mut left = 0;
        let mut right = digit.len() - 1;

        while left < right {
            if digit[left] != digit[right] {
                return false;
            }

            left += 1;
            right -= 1;
        }

        return true;
    }
}

impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {
            return false;
        }

        if x == 0 {
            return true;
        }

        let mut reverse = 0;
        let mut num = x;

        while num != 0 {
            reverse *= 10;
            reverse += num % 10;
            num /= 10;
        }

        return x == reverse;
    }
}
