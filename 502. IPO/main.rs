struct Solution;

use std::collections::BinaryHeap;

impl Solution {
    pub fn find_maximized_capital(k: i32, w: i32, profits: Vec<i32>, capital: Vec<i32>) -> i32 {
        let size = capital.len();
        let mut k = k;
        let mut w = w;
        let mut i = 0;
        let mut max_heap = BinaryHeap::new();
        let mut ipo = capital
            .into_iter()
            .zip(profits.into_iter())
            .collect::<Vec<_>>();
        ipo.sort_by(|a, b| a.0.cmp(&b.0));

        while k > 0 {
            k -= 1;
            while i < size && ipo[i].0 <= w {
                max_heap.push(ipo[i].1);
                i += 1;
            }

            if let Some(value) = max_heap.pop() {
                w += value;
            } else {
                break;
            }
        }

        w
    }
}
