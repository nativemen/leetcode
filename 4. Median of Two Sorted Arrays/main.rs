struct Solution;

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let mut nums = nums1;
        let mut nums2 = nums2;
        nums.append(&mut nums2);
        nums.sort();

        let nums_size = nums.len();
        if nums_size % 2 != 0 {
            return nums[nums_size / 2] as f64;
        } else {
            return (nums[nums_size / 2 - 1] + nums[nums_size / 2]) as f64 / 2.0;
        }
    }
}

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let nums1_size = nums1.len();
        let nums2_size = nums2.len();
        let nums_size = nums1_size + nums2_size;
        let mut i = 0;
        let mut j = 0;
        let mut m1 = 0;
        let mut m2 = 0;

        for _ in 0..(nums_size / 2 + 1) {
            m1 = m2;

            if i == nums1_size {
                m2 = nums2[j];
                j += 1;
            } else if j == nums2_size {
                m2 = nums1[i];
                i += 1;
            } else if nums1[i] < nums2[j] {
                m2 = nums1[i];
                i += 1;
            } else {
                m2 = nums2[j];
                j += 1;
            }
        }

        if nums_size % 2 != 0 {
            m2 as f64
        } else {
            (m1 + m2) as f64 / 2.0
        }
    }
}
