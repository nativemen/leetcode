struct Solution;

use std::collections::HashSet;

impl Solution {
    pub fn find_difference(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<Vec<i32>> {
        let mut set1: HashSet<i32> = HashSet::from_iter(nums1.iter().cloned());
        let mut set2: HashSet<i32> = HashSet::from_iter(nums2.iter().cloned());

        for num in nums1.iter() {
            if set2.contains(num) {
                set1.remove(num);
                set2.remove(num);
            }
        }

        vec![set1.into_iter().collect(), set2.into_iter().collect()]
    }
}

use std::collections::HashSet;

impl Solution {
    pub fn find_difference(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<Vec<i32>> {
        let set1: HashSet<i32> = nums1.into_iter().collect();
        let set2: HashSet<i32> = nums2.into_iter().collect();
        let diff1 = set1
            .iter()
            .filter(|num| !set2.contains(num))
            .cloned()
            .collect();
        let diff2 = set2
            .iter()
            .filter(|num| !set1.contains(num))
            .cloned()
            .collect();

        vec![diff1, diff2]
    }
}
