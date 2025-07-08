struct Solution;

struct SmallestInfiniteSet {
    array: Vec<bool>,
    smallest: usize,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl SmallestInfiniteSet {

    fn new() -> Self {
        Self {
            array: vec![true; 1002],
            smallest: 1,
        }
    }

    fn pop_smallest(&mut self) -> i32 {
        let result = self.smallest as i32;
        self.array[self.smallest] = false;

        for i in self.smallest + 1..1002 {
            if self.array[i] {
                self.smallest = i;
                break;
            }
        }

        result
    }

    fn add_back(&mut self, num: i32) {
        self.array[num as usize] = true;

        if num < self.smallest as i32 {
            self.smallest = num as usize;
        }
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * let obj = SmallestInfiniteSet::new();
 * let ret_1: i32 = obj.pop_smallest();
 * obj.add_back(num);
 */

use std::collections::BTreeSet;

struct SmallestInfiniteSet {
    set: BTreeSet<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl SmallestInfiniteSet {

    fn new() -> Self {
        let v = (1..=1001).collect::<Vec<_>>();
        Self {
            set: BTreeSet::from_iter(v),
        }
    }

    fn pop_smallest(&mut self) -> i32 {
        if let Some(result) = self.set.pop_first() {
            return result;
        }

        -1
    }

    fn add_back(&mut self, num: i32) {
        self.set.insert(num);
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * let obj = SmallestInfiniteSet::new();
 * let ret_1: i32 = obj.pop_smallest();
 * obj.add_back(num);
 */