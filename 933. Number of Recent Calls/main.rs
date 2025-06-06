struct Solution;

use std::collections::VecDeque;

struct RecentCounter {
    time: VecDeque<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RecentCounter {
    fn new() -> Self {
        Self {
            time: VecDeque::new(),
        }
    }

    fn ping(&mut self, t: i32) -> i32 {
        self.time.push_back(t);

        while let Some(val) = self.time.front() {
            if (val + 3000 >= t) {
                break;
            }
            self.time.pop_front();
        }

        self.time.len() as i32
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * let obj = RecentCounter::new();
 * let ret_1: i32 = obj.ping(t);
 */

struct RecentCounter {
    time: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RecentCounter {
    fn new() -> Self {
        Self {
            time: Vec::new(),
        }
    }

    fn ping(&mut self, t: i32) -> i32 {
        self.time.push(t);

        while self.time[0] + 3000 < t {
            self.time.remove(0);
        }

        self.time.len() as i32
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * let obj = RecentCounter::new();
 * let ret_1: i32 = obj.ping(t);
 */


struct RecentCounter {
    time: Vec<i32>,
    head: usize,
    tail: usize,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RecentCounter {
    fn new() -> Self {
        Self {
            time: vec![0; 10001],
            head: 0,
            tail: 0,
        }
    }

    fn ping(&mut self, t: i32) -> i32 {
        self.time[self.tail] = t;
        self.tail += 1;

        while self.time[self.head] + 3000 < t {
            self.head += 1;
        }

        (self.tail - self.head) as i32
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * let obj = RecentCounter::new();
 * let ret_1: i32 = obj.ping(t);
 */