struct Solution;

impl Solution {
    pub fn trailing_zeroes(n: i32) -> i32 {
        if n == 0 {
            return 0;
        }

        let mut count = 0;
        let mut num = n;

        while num % 5 == 0 {
            count += 1;
            num /= 5;
        }

        count + Self::trailing_zeroes(n - 1)
    }
}

impl Solution {
    pub fn trailing_zeroes(n: i32) -> i32 {
        if n == 0 {
            return 0;
        }

        n / 5 + Self::trailing_zeroes(n / 5)
    }
}

impl Solution {
    pub fn trailing_zeroes(n: i32) -> i32 {
        let mut count = 0;
        let mut num = n;

        while num >= 5 {
            num /= 5;
            count += num;
        }

        count
    }
}
