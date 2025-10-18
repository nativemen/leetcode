use std::collections::HashMap;

struct TimeMap {
    maps: HashMap<String, Vec<(i32, String)>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl TimeMap {
    fn new() -> Self {
        Self {
            maps: HashMap::new(),
        }
    }

    fn set(&mut self, key: String, value: String, timestamp: i32) {
        self.maps
            .entry(key)
            .and_modify(|v| v.push((timestamp, value.clone())))
            .or_insert(vec![(timestamp, value)]);
    }

    fn get(&self, key: String, timestamp: i32) -> String {
        if let Some(v) = self.maps.get(&key) {
            let mut left = 0;
            let mut right = v.len() as i32 - 1;

            while left <= right {
                let mid = left + (right - left) / 2;

                if v[mid as usize].0 <= timestamp {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if right < 0 {
                return "".to_string();
            }

            v[right as usize].1.clone()
        } else {
            "".to_string()
        }
    }
}


/**
 * Your TimeMap object will be instantiated and called as such:
 * let obj = TimeMap::new();
 * obj.set(key, value, timestamp);
 * let ret_2: String = obj.get(key, timestamp);
 */