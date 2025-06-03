struct Solution;

impl Solution {
    pub fn largest_altitude(gain: Vec<i32>) -> i32 {
        let mut altitude = 0;
        let mut largest = 0;

        for val in gain.into_iter() {
            altitude += val;
            largest = largest.max(altitude);
        }

        largest
    }
}

impl Solution {
    pub fn largest_altitude(gain: Vec<i32>) -> i32 {
        let mut altitudes = vec![0];

        for i in 1..=gain.len() {
            altitudes.push(altitudes[i - 1] + gain[i - 1]);
        }

        altitudes.into_iter().max().unwrap()
    }
}
