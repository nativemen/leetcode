struct LRUCache {
    cap: i32,
    count: i32,
    values: Vec<i32>,
    freq: Vec<i32>,
    que: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LRUCache {
    fn new(capacity: i32) -> Self {
        const ARRAY_SIZE: usize = 10001;

        Self {
            cap: capacity,
            count: 0,
            values: vec![-1; ARRAY_SIZE],
            freq: vec![0; ARRAY_SIZE],
            que: Vec::new(),
        }
    }

    fn get(&mut self, key: i32) -> i32 {
        if self.count == 0 {
            return -1;
        }

        if self.values[key as usize] == -1 {
            return -1;
        }

        self.freq[key as usize] += 1;
        self.que.push(key);

        return self.values[key as usize];
    }

    fn put(&mut self, key: i32, value: i32) {
        if self.values[key as usize] == -1 {
            while self.count >= self.cap {
                let del_key = self.que.remove(0) as usize;

                if self.freq[del_key] == 1 {
                    self.values[del_key] = -1;
                    self.count -= 1;
                }

                self.freq[del_key] -= 1;
            }

            self.freq[key as usize] = 1;
            self.count += 1;
        } else {
            self.freq[key as usize] += 1;
        }

        self.values[key as usize] = value;
        self.que.push(key);
    }
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * let obj = LRUCache::new(capacity);
 * let ret_1: i32 = obj.get(key);
 * obj.put(key, value);
 */
