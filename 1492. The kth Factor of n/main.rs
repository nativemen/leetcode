struct Solution;

impl Solution {
    pub fn kth_factor(n: i32, k: i32) -> i32 {
        let mut num = 1;
        let mut k = k;

        while num <= n {
            if n % num == 0 {
                k -= 1;
                if k == 0 {
                    return num;
                }
            }

            num += 1;
        }

        -1
    }
}

impl Solution {
    pub fn kth_factor(n: i32, k: i32) -> i32 {
        let mut count = 0;

        for i in 1..=n {
            if n % i == 0 {
                count += 1;
                if count == k {
                    return i;
                }
            }
        }

        -1
    }
}

impl Solution {
    pub fn kth_factor(n: i32, k: i32) -> i32 {
        let mut fact = Vec::new();

        for i in 1..=n {
            if n % i == 0 {
                fact.push
            }
        }

        -1
    }
}
