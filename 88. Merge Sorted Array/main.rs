struct Solution;

impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        for i in 0..n {
            nums1[(m + i) as usize] = nums2[i as usize];
        }
        nums1.sort();
    }
}

impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        let mut i = m - 1;
        let mut j = n - 1;
        let mut k = m + n - 1;

        while i >= 0 && j >= 0 {
            if nums1[i as usize] > nums2[j as usize] {
                nums1[k as usize] = nums1[i as usize];
                i -= 1;
            } else {
                nums1[k as usize] = nums2[j as usize];
                j -= 1;
            }
            k -= 1;
        }

        while j >= 0 {
            nums1[k as usize] = nums2[j as usize];
            k -= 1;
            j -= 1;
        }
    }
}

impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        nums1[m as usize..].swap_with_slice(nums2);
        nums1.sort();
    }
}
