use rand::seq::SliceRandom;
use rand::thread_rng;

struct Solution {
    orig: Vec<i32>,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {

    fn new(nums: Vec<i32>) -> Self {
        Self {
            orig : nums.clone(),
        }
    }

    fn reset(&self) -> Vec<i32> {
        self.orig.clone()
    }

    fn shuffle(&self) -> Vec<i32> {
        let mut shuf = self.orig.clone();
        shuf.shuffle(&mut thread_rng());

        shuf
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution::new(nums);
 * let ret_1: Vec<i32> = obj.reset();
 * let ret_2: Vec<i32> = obj.shuffle();
 */

use rand::seq::SliceRandom;
use rand::{thread_rng, Rng};

struct Solution {
    orig: Vec<i32>,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {

    fn new(nums: Vec<i32>) -> Self {
        Self {
            orig : nums.clone(),
        }
    }

    fn reset(&self) -> Vec<i32> {
        self.orig.clone()
    }

    fn shuffle(&self) -> Vec<i32> {
        let mut shuf = self.orig.clone();
        let mut rng = thread_rng();
        let size = shuf.len();
        for i in 0..size {
            shuf.swap(i, rng.gen_range(i..size));
        }

        shuf
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution::new(nums);
 * let ret_1: Vec<i32> = obj.reset();
 * let ret_2: Vec<i32> = obj.shuffle();
 */

use rand::rngs::StdRng;
use rand::{SeedableRng, seq::SliceRandom};

struct Solution {
    orig: Vec<i32>,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {

    fn new(nums: Vec<i32>) -> Self {
        Self {
            orig : nums.clone(),
        }
    }

    fn reset(&self) -> Vec<i32> {
        self.orig.clone()
    }

    fn shuffle(&self) -> Vec<i32> {
        let mut shuf = self.orig.clone();
        let mut rng = StdRng::from_entropy();
        shuf.shuffle(&mut rng);

        shuf
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution::new(nums);
 * let ret_1: Vec<i32> = obj.reset();
 * let ret_2: Vec<i32> = obj.shuffle();
 */