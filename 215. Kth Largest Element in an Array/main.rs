struct Solution;

impl Solution {
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        let mut nums = nums;

        nums.sort();

        nums[nums.len() - k as usize]
    }
}

impl Solution {
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        const ARRAY_SIZE: usize = 20001;
        const INDEX_OFFSET: usize = 10000;
        let mut count = vec![0; ARRAY_SIZE];
        let mut k = k;

        for &num in nums.iter() {
            count[num as usize + INDEX_OFFSET] += 1;
        }

        for i in (0..ARRAY_SIZE).rev() {
            if k <= count[i] {
                return i as i32 - INDEX_OFFSET as i32;
            }

            k -= count[i];
        }

        0 - INDEX_OFFSET as i32
    }
}

use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        if nums.is_empty() || k < 0 || k > nums.len() as i32 {
            return -1;
        }

        let mut min_heap =
            BinaryHeap::from_iter(nums[..k as usize].iter().map(|&num| Reverse(num)));

        for i in k as usize..nums.len() {
            if let Some(&Reverse(top)) = min_heap.peek() {
                if (nums[i] > top) {
                    min_heap.pop();
                    min_heap.push(Reverse(nums[i]));
                }
            }
        }

        match min_heap.into_iter().map(|Reverse(num)| num).min() {
            Some(value) => value,
            _ => -1,
        }
    }
}

use rand::random;
use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
    fn quick_select(nums: &Vec<i32>, k: usize) -> i32 {
        let nums_size = nums.len();
        let pivot = nums[rand::random::<i32>() as usize % nums_size];
        let mut left = Vec::new();
        let mut right = Vec::new();
        let mut mid = Vec::new();
        let mut i = 0;

        while i < nums_size {
            if nums[i] < pivot {
                left.push(nums[i]);
            } else if nums[i] > pivot {
                right.push(nums[i]);
            } else {
                mid.push(nums[i]);
            }

            i += 1;
        }

        if right.len() >= k {
            Self::quick_select(&right, k)
        } else if right.len() + mid.len() < k {
            Self::quick_select(&left, k - right.len() - mid.len())
        } else {
            pivot
        }
    }

    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        if nums.is_empty() || k < 0 || k > nums.len() as i32 {
            return -1;
        }

        Self::quick_select(&nums, k as usize)
    }
}
