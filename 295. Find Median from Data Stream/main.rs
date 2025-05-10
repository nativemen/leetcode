use std::collections::BinaryHeap;

struct MedianFinder {
    max_heap: BinaryHeap<i32>,
    min_heap: BinaryHeap<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MedianFinder {
    fn new() -> Self {
        Self {
            max_heap: BinaryHeap::new(),
            min_heap: BinaryHeap::new(),
        }
    }

    fn add_num(&mut self, num: i32) {
        if self.max_heap.is_empty() || num < *self.max_heap.peek().unwrap() {
            self.max_heap.push(num);
        } else {
            self.min_heap.push(-num);
        }

        while self.max_heap.len() > self.min_heap.len() + 1 {
            self.min_heap.push(-self.max_heap.pop().unwrap());
        }

        while self.max_heap.len() < self.min_heap.len() {
            self.max_heap.push(-self.min_heap.pop().unwrap());
        }
    }

    fn find_median(&self) -> f64 {
        if self.max_heap.len() == self.min_heap.len() {
            if self.max_heap.is_empty() {
                return 0.0;
            }

            return (*self.max_heap.peek().unwrap() - *self.min_heap.peek().unwrap()) as f64 / 2.0;
        }

        return *self.max_heap.peek().unwrap() as f64;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * let obj = MedianFinder::new();
 * obj.add_num(num);
 * let ret_2: f64 = obj.find_median();
 */

use std::cmp::Reverse;
use std::collections::BinaryHeap;

struct MedianFinder {
    max_heap: BinaryHeap<i32>,
    min_heap: BinaryHeap<Reverse<i32>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MedianFinder {
    fn new() -> Self {
        Self {
            max_heap: BinaryHeap::new(),
            min_heap: BinaryHeap::new(),
        }
    }

    fn add_num(&mut self, num: i32) {
        if self.max_heap.is_empty() || num < *self.max_heap.peek().unwrap() {
            self.max_heap.push(num);
        } else {
            self.min_heap.push(Reverse(num));
        }

        while self.max_heap.len() > self.min_heap.len() + 1 {
            self.min_heap.push(Reverse(self.max_heap.pop().unwrap()));
        }

        while self.max_heap.len() < self.min_heap.len() {
            let Reverse(n) = self.min_heap.pop().unwrap();
            self.max_heap.push(n);
        }
    }

    fn find_median(&self) -> f64 {
        if self.max_heap.len() == self.min_heap.len() {
            if self.max_heap.is_empty() {
                return 0.0;
            }

            let &Reverse(n) = self.min_heap.peek().unwrap();
            return (*self.max_heap.peek().unwrap() + n) as f64 / 2.0;
        }

        return *self.max_heap.peek().unwrap() as f64;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * let obj = MedianFinder::new();
 * obj.add_num(num);
 * let ret_2: f64 = obj.find_median();
 */