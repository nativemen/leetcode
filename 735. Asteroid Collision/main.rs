struct Solution;

impl Solution {
    pub fn asteroid_collision(asteroids: Vec<i32>) -> Vec<i32> {
        let mut result = Vec::new();
        let mut i = 0;
        let asteroids_size = asteroids.len();

        while i < asteroids_size {
            if result.is_empty() || *result.last().unwrap() < 0 || asteroids[i] >= 0 {
                result.push(asteroids[i]);
                i += 1;
            } else {
                let sum = *result.last().unwrap() + asteroids[i];
                if sum < 0 {
                    result.pop();
                } else if sum == 0 {
                    result.pop();
                    i += 1;
                } else {
                    i += 1;
                }
            }
        }

        result
    }
}
