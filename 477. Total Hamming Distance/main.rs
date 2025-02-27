struct Solution;

impl Solution {
    pub fn total_hamming_distance(nums: Vec<i32>) -> i32 {
        let mut total = 0;
        let size = nums.len();

        for i in 0..32 {
            let mut bit_count = 0;
            for j in 0..size {
                bit_count += (nums[j] >> i) & 1;
            }
            total += bit_count * (size as i32 - bit_count);
        }

        total
    }
}

impl Solution {
    pub fn total_hamming_distance(nums: Vec<i32>) -> i32 {
        let mut total = 0;
        let size = nums.len();

        for i in 0..size - 1 {
            for j in i + 1..size {
                total += (nums[i] ^ nums[j]).count_ones();
            }
        }

        total as i32
    }
}

impl Solution {
    pub fn total_hamming_distance(nums: Vec<i32>) -> i32 {
        let mut bit_count = [0; 32];
        let size = nums.len();

        nums.iter().for_each(|n| {
            (0..32).for_each(|i| {
                bit_count[i] += (n >> i) & 1;
            })
        });

        bit_count
            .iter()
            .map(|count| count * (size as i32 - count))
            .sum()
    }
}
