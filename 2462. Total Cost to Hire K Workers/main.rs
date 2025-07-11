struct Solution;

use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
    pub fn total_cost(costs: Vec<i32>, k: i32, candidates: i32) -> i64 {
        let mut heap1 = BinaryHeap::new();
        let mut heap2 = BinaryHeap::new();
        let mut left = 0;
        let mut right = costs.len() - 1;

        while left <= right && heap1.len() < candidates as usize {
            heap1.push(Reverse(costs[left]));
            left += 1;
        }

        while left <= right && heap2.len() < candidates as usize {
            heap2.push(Reverse(costs[right]));
            right -= 1;
        }

        let mut total = 0;
        let mut k = k;

        while k > 0 {
            let pop_heap1 = match (heap1.peek(), heap2.peek()) {
                (Some(&Reverse(val1)), Some(&Reverse(val2))) => val1 <= val2,
                (Some(_), None) => true,
                (None, Some(_)) => false,
                (None, None) => break,
            };

            if pop_heap1 {
                if let Some(Reverse(value)) = heap1.pop() {
                    total += value as i64;
                }

                if left <= right {
                    heap1.push(Reverse(costs[left]));
                    left += 1;
                }
            } else {
                if let Some(Reverse(value)) = heap2.pop() {
                    total += value as i64;
                }
                if left <= right {
                    heap2.push(Reverse(costs[right]));
                    right -= 1;
                }
            }

            k -= 1;
        }

        total
    }
}
