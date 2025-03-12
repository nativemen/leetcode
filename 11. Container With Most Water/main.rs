struct Solution;

impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut right = height.len() - 1;
        let mut m_area = 0;

        while left < right {
            let area = (right - left) as i32 * height[left].min(height[right]);
            m_area = m_area.max(area);

            if height[left] < height[right] {
                left += 1;
            } else {
                right -= 1;
            }
        }

        m_area
    }
}
