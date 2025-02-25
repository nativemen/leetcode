struct Solution;

impl Solution {
    pub fn count_primes(n: i32) -> i32 {
        let mut is_primes = vec![true; n as usize];
        let mut count = 0;

        for i in 2..n as usize {
            if is_primes[i] {
                count += 1;
                for j in (i * i..n as usize).step_by(i) {
                    is_primes[j] = false;
                }
            }
        }

        count
    }
}
