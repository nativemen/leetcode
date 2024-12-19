use std::collections::HashSet;

struct Solution;

impl Solution {
    pub fn intersection(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        HashSet::<i32>::from_iter(nums1.iter().cloned())
            .intersection(&HashSet::<i32>::from_iter(nums2.iter().cloned()))
            .cloned()
            .collect::<Vec<i32>>()
    }
}

impl Solution {
    pub fn intersection(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut nums1 = nums1;
        let mut nums2 = nums2;

        nums1.sort_unstable();
        nums2.sort_unstable();
        nums1.dedup();
        nums2.dedup();

        let mut result = Vec::new();
        let mut i = 0;
        let mut j = 0;
        let len1 = nums1.len();
        let len2 = nums2.len();
        while (i < len1 && j < len2) {
            if (nums1[i] < nums2[j]) {
                i += 1;
            } else if (nums1[i] > nums2[j]) {
                j += 1;
            } else {
                result.push(nums1[i]);
                i += 1;
                j += 1;
            }
        }

        result
    }
}

impl Solution {
    pub fn intersection(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut nums1 = nums1;
        let mut nums2 = nums2;

        nums1.sort();
        nums2.sort();
        nums1.dedup();
        nums2.dedup();

        nums1.retain(|x| nums2.contains(x));

        nums1
    }
}
