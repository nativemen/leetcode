struct Solution;

impl Solution {
    pub fn max_points(points: Vec<Vec<i32>>) -> i32 {
        let mut max_points = 1;
        let size = points.len();

        for i in 0..size {
            let x1 = points[i][0];
            let y1 = points[i][1];
            for j in i + 1..size {
                let x2 = points[j][0];
                let y2 = points[j][1];
                let mut total = 2;

                for k in 0..size {
                    if k == i || k == j {
                        continue;
                    }

                    let x = points[k][0];
                    let y = points[k][1];

                    if (y1 - y) * (x2 - x) == (y2 - y) * (x1 - x) {
                        total += 1;
                    }
                }

                max_points = max_points.max(total);
            }
        }

        max_points
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn max_points(points: Vec<Vec<i32>>) -> i32 {
        let mut max_points = 1;
        let size = points.len();

        for i in 0..size {
            let mut map = HashMap::new();
            for j in i + 1..size {
                let mut slope = 0;
                if points[j][0] == points[i][0] {
                    slope = f32::MAX.to_bits();
                } else if (points[j][1] == points[i][1]) {
                    slope = 0.0f32.to_bits();
                } else {
                    slope = ((points[j][1] - points[i][1]) as f32
                        / (points[j][0] - points[i][0]) as f32)
                        .to_bits();
                }
                *map.entry(slope).or_insert(0) += 1;
            }

            for value in map.values() {
                max_points = max_points.max(value + 1);
            }
        }

        max_points
    }
}
