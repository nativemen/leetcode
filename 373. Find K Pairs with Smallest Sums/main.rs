struct Solution;

use std::collections::BinaryHeap;

impl Solution {
    pub fn k_smallest_pairs(nums1: Vec<i32>, nums2: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        let len1 = nums1.len();
        let len2 = nums2.len();
        let mut result = Vec::new();

        if len1 == 0 || len2 == 0 || k <= 0 {
            return result;
        }

        let mut max_heap = BinaryHeap::from_iter([(-nums1[0] - nums2[0], 0, 0)].into_iter());
        let mut k = k;

        while k > 0 && !max_heap.is_empty() {
            k -= 1;
            if let Some((_, i, j)) = max_heap.pop() {
                result.push(vec![nums1[i], nums2[j]]);

                if j == 0 && i + 1 < len1 {
                    let item = (-nums1[i + 1] - nums2[j], i + 1, j);
                    max_heap.push(item);
                }

                if j + 1 < len2 {
                    let item = (-nums1[i] - nums2[j + 1], i, j + 1);
                    max_heap.push(item);
                }
            }
        }

        result
    }
}

use std::collections::BinaryHeap;

impl Solution {
    pub fn k_smallest_pairs(nums1: Vec<i32>, nums2: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        let len1 = nums1.len();
        let len2 = nums2.len();
        let mut result = Vec::new();

        if len1 == 0 || len2 == 0 || k <= 0 {
            return result;
        }

        let mut min_heap = BinaryHeap::from_iter(
            nums1
                .iter()
                .enumerate()
                .map(|(i, &num1)| (-num1 - nums2[0], i, 0)),
        );
        let mut k = k;

        while k > 0 && !min_heap.is_empty() {
            k -= 1;
            if let Some((_, i, j)) = min_heap.pop() {
                result.push(vec![nums1[i], nums2[j]]);

                if j + 1 < len2 {
                    min_heap.push((-nums1[i] - nums2[j + 1], i, j + 1));
                }
            }
        }

        result
    }
}

use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
    pub fn k_smallest_pairs(nums1: Vec<i32>, nums2: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        let len1 = nums1.len();
        let len2 = nums2.len();
        let mut result = Vec::new();

        if len1 == 0 || len2 == 0 || k <= 0 {
            return result;
        }

        let mut min_heap = BinaryHeap::from_iter(
            nums1
                .iter()
                .enumerate()
                .map(|(i, &num1)| (Reverse(num1 + nums2[0]), i, 0)),
        );
        let mut k = k;

        while k > 0 && !min_heap.is_empty() {
            k -= 1;
            if let Some((_, i, j)) = min_heap.pop() {
                result.push(vec![nums1[i], nums2[j]]);

                if j + 1 < len2 {
                    min_heap.push((Reverse(nums1[i] + nums2[j + 1]), i, j + 1));
                }
            }
        }

        result
    }
}
