struct Solution;

impl Solution {
    pub fn my_pow(x: f64, n: i32) -> f64 {
        x.powf(n)
    }
}

impl Solution {
    pub fn my_pow(x: f64, n: i32) -> f64 {
        if x.abs() < f64::EPSILON {
            return 0.0;
        }

        if n == 0 {
            return 1.0;
        }

        if n < 0 {
            return 1.0 / (x * Self::my_pow(x, -1 - n));
        }

        let power = Self::my_pow(x, n / 2);

        if n % 2 == 0 {
            return power * power;
        }

        x * power * power
    }
}

impl Solution {
    pub fn my_pow(x: f64, n: i32) -> f64 {
        if x.abs() < f64::EPSILON {
            return 0.0;
        }

        if n == 0 {
            return 1.0;
        }

        let mut num = n as i64;
        let mut x = x;
        if num < 0 {
            x = 1.0 / x;
            num = -num;
        }

        let mut result = 1.0;

        while num > 0 {
            if num % 2 == 1 {
                result *= x;
            }

            x *= x;
            num /= 2;
        }

        result
    }
}
