struct Solution;

impl Solution {
    pub fn is_happy(n: i32) -> bool {
        let mut history = Vec::new();
        let mut num = n;

        while !history.contains(&num) {
            if num == 1 {
                return true;
            }

            history.push(num);

            let mut sum = 0;

            while num != 0 {
                let digit = num % 10;
                sum += digit * digit;
                num /= 10;
            }

            num = sum;
        }

        false
    }
}

use std::collections::HashSet;

impl Solution {
    pub fn is_happy(n: i32) -> bool {
        let mut history = HashSet::new();
        let mut num = n;

        while !history.contains(&num) {
            if num == 1 {
                return true;
            }

            history.insert(num);

            let mut sum = 0;

            while num != 0 {
                let digit = num % 10;
                sum += digit * digit;
                num /= 10;
            }

            num = sum;
        }

        false
    }
}

impl Solution {
    pub fn is_happy(n: i32) -> bool {
        let mut slow = n;
        let mut fast = n;

        while fast != 1 && Self::compute_next(fast) != 1 {
            slow = Self::compute_next(slow);
            fast = Self::compute_next(Self::compute_next(fast));

            if slow == fast {
                return false;
            }
        }

        true
    }

    fn compute_next(n: i32) -> i32 {
        let mut sum = 0;
        let mut num = n;

        while num != 0 {
            let digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }

        sum
    }
}

impl Solution {
    pub fn is_happy(n: i32) -> bool {
        if n == 1 || n == 7 {
            return true;
        }

        if n < 10 {
            return false;
        }

        let mut sum = 0;
        let mut num = n;

        while num != 0 {
            let digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }

        Self::is_happy(sum)
    }
}
