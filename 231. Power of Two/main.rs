struct Solution;

impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        let mut val = 1;

        while val < n as i64 {
            val *= 2;
        }

        if val == n as i64 {
            return true;
        }

        false
    }
}

impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        if n == 1 {
            true
        } else if n < 1 {
            false
        } else if n % 2 == 0 {
            Self::is_power_of_two(n / 2)
        } else {
            false
        }
    }
}

impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        if n == 1 {
            return true;
        }

        if n < 1 || n % 2 != 0 {
            return false;
        }

        Self::is_power_of_two(n / 2)
    }
}

impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        n > 0 && 1073741824 % n == 0
    }
}

impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        n > 0 && n.count_ones() == 1
    }
}

impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        n > 0 && (n & (n - 1)) == 0
    }
}
