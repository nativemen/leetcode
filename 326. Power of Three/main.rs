struct Solution;

impl Solution {
    pub fn is_power_of_three(n: i32) -> bool {
        let mut val: i64 = 1;

        while val < n as i64 {
            val *= 3;
        }

        if (val == n as i64) {
            return true;
        }

        return false;
    }
}

impl Solution {
    pub fn is_power_of_three(n: i32) -> bool {
        if n == 1 {
            return true;
        }

        if n < 1 || n == 2 {
            return false;
        }

        if n % 3 == 0 {
            return Self::is_power_of_three(n / 3);
        }

        return false;
    }
}

impl Solution {
    pub fn is_power_of_three(n: i32) -> bool {
        if n == 1 {
            return true;
        }

        if n < 1 || n % 3 != 0 {
            return false;
        }

        return Self::is_power_of_three(n / 3);
    }
}


impl Solution {
    pub fn is_power_of_three(n: i32) -> bool {
        return n > 0 && 1162261467 % n == 0;
    }
}