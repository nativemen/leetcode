struct Solution;

impl Solution {
    pub fn count_bits(n: i32) -> Vec<i32> {
        let mut counter = vec![0; n as usize + 1];

        for num in 0..=n {
            for i in 0..32 {
                counter[num as usize] += (num >> i) & 1;
            }
        }

        return counter;
    }
}

impl Solution {
    pub fn count_bits(n: i32) -> Vec<i32> {
        let mut counter = vec![0; n as usize + 1];

        for num in 0..=n as usize {
            counter[num] = num.count_ones() as i32;
        }

        return counter;
    }
}

impl Solution {
    pub fn count_bits(n: i32) -> Vec<i32> {
        let mut counter = vec![0; n as usize + 1];

        for num in 0..=n as usize {
            counter[num] = counter[num >> 1] + (num & 1) as i32;
        }

        return counter;
    }
}

impl Solution {
    pub fn count_bits(n: i32) -> Vec<i32> {
        (0..=n).map(|num| num.count_ones() as i32).collect()
    }
}
