use std::collections::HashSet;
use rand::Rng;

struct RandomizedSet {
    set: HashSet<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RandomizedSet {
    fn new() -> Self {
        RandomizedSet{
            set: HashSet::new(),
        }
    }

    fn insert(&mut self, val: i32) -> bool {
        self.set.insert(val)
    }

    fn remove(&mut self, val: i32) -> bool {
        self.set.remove(&val)
    }

    fn get_random(&self) -> i32 {
        let mut rng = rand::thread_rng();
        let number =rng.gen_range(0..self.set.len());
        *self.set.iter().nth(number).unwrap()
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * let obj = RandomizedSet::new();
 * let ret_1: bool = obj.insert(val);
 * let ret_2: bool = obj.remove(val);
 * let ret_3: i32 = obj.get_random();
 */


use std::collections::HashMap;
use rand::Rng;

struct RandomizedSet {
    vec: Vec<i32>,
    map: HashMap<i32, usize>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RandomizedSet {
    fn new() -> Self {
        RandomizedSet{
            vec: Vec::new(),
            map: HashMap::new(),
        }
    }

    fn insert(&mut self, val: i32) -> bool {
        if self.map.contains_key(&val) {
            return false;
        }

        self.vec.push(val);
        self.map.insert(val, self.vec.len() - 1);

        return true;
    }

    fn remove(&mut self, val: i32) -> bool {
        if let Some(&index) = self.map.get(&val) {
            let last_val = *self.vec.last().unwrap();
            self.vec[index] = last_val;
            self.map.insert(last_val, index);
            self.vec.pop();
            self.map.remove(&val);

            return true;
        }

        false
    }

    fn get_random(&self) -> i32 {
        let mut rng = rand::thread_rng();
        let index =rng.gen_range(0..self.vec.len());
        self.vec[index]
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * let obj = RandomizedSet::new();
 * let ret_1: bool = obj.insert(val);
 * let ret_2: bool = obj.remove(val);
 * let ret_3: i32 = obj.get_random();
 */