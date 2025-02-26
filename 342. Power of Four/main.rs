struct Solution;

impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        let mut val: i64 = 1;

        while val < n as i64 {
            val *= 4;
        }

        if (val == n as i64) {
            return true;
        }

        return false;
    }
}

impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        if n == 1 {
            return true;
        }

        if n < 1 {
            return false;
        }

        if n % 4 == 0 {
            return Self::is_power_of_four(n / 4);
        }

        return false;
    }
}

impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        if n == 1 {
            return true;
        }

        if n < 1 || n % 4 != 0 {
            return false;
        }

        return Self::is_power_of_four(n / 4);
    }
}

impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        let mut n = n;

        if n < 1 {
            return false;
        }

        while n % 4 == 0 {
            n /= 4;
        }

        n == 1
    }
}
