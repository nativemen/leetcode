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
use std::cell::RefCell;
use std::collections::HashMap;
use std::rc::{Rc, Weak};

#[derive(Debug)]
struct ListNode {
    key: i32,
    value: i32,
    next: Option<Rc<RefCell<ListNode>>>,
    prev: Option<Weak<RefCell<ListNode>>>,
}

#[derive(Debug)]
pub struct LRUCache {
    capacity: usize,
    map: HashMap<i32, Rc<RefCell<ListNode>>>,
    head: Option<Rc<RefCell<ListNode>>>,
    tail: Option<Weak<RefCell<ListNode>>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LRUCache {
    pub fn new(capacity: i32) -> Self {
        Self {
            capacity: capacity as usize,
            map: HashMap::new(),
            head: None,
            tail: None,
        }
    }

    pub fn get(&mut self, key: i32) -> i32 {
        if let Some(node) = self.map.get(&key) {
            let value = node.borrow().value;
            self.move_to_front(node.clone());
            value
        } else {
            -1
        }
    }

    pub fn put(&mut self, key: i32, value: i32) {
        if self.capacity == 0 {
            return;
        }

        if let Some(node) = self.map.get(&key) {
            node.borrow_mut().value = value;
            self.move_to_front(node.clone());
            return;
        }

        if self.map.len() >= self.capacity {
            self.evict();
        }

        let new_node = Rc::new(RefCell::new(ListNode {
            key,
            value,
            next: None,
            prev: None,
        }));

        self.add_to_front(new_node.clone());
        self.map.insert(key, new_node);
    }

    fn move_to_front(&mut self, node: Rc<RefCell<ListNode>>) {
        // No need to move if it's already the head node
        if let Some(head) = &self.head {
            if Rc::ptr_eq(head, &node) {
                return;
            }
        }

        // Handle node's connections
        let next = node.borrow().next.clone();
        let prev = node.borrow().prev.clone();

        // Update adjacent nodes' connections
        if let Some(prev) = prev.and_then(|w| w.upgrade()) {
            if let Some(next) = &next {
                prev.borrow_mut().next = Some(next.clone());
                next.borrow_mut().prev = Some(Rc::downgrade(&prev));
            } else {
                // If it's the tail node
                prev.borrow_mut().next = None;
                self.tail = Some(Rc::downgrade(&prev));
            }
        }

        // Move the node to the front
        if let Some(old_head) = self.head.take() {
            old_head.borrow_mut().prev = Some(Rc::downgrade(&node));
            node.borrow_mut().next = Some(old_head);
            node.borrow_mut().prev = None;
        }

        self.head = Some(node);
    }

    fn evict(&mut self) {
        if let Some(tail_weak) = self.tail.take() {
            if let Some(tail_node) = tail_weak.upgrade() {
                let key = tail_node.borrow().key;
                self.map.remove(&key);

                // Update tail to point to the previous node
                if let Some(prev) = tail_node.borrow().prev.as_ref().and_then(|w| w.upgrade()) {
                    prev.borrow_mut().next = None;
                    self.tail = Some(Rc::downgrade(&prev));
                } else {
                    // If there's no previous node, the list will be empty
                    self.head = None;
                    self.tail = None;
                }
            }
        }
    }

    fn add_to_front(&mut self, node: Rc<RefCell<ListNode>>) {
        match self.head.take() {
            Some(old_head) => {
                // List is not empty, update head
                old_head.borrow_mut().prev = Some(Rc::downgrade(&node));
                node.borrow_mut().next = Some(old_head);
                node.borrow_mut().prev = None;
                self.head = Some(node);
            }
            None => {
                // List is empty, update both head and tail
                self.head = Some(node.clone());
                self.tail = Some(Rc::downgrade(&node));
            }
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * let obj = LRUCache::new(capacity);
 * let ret_1: i32 = obj.get(key);
 * obj.put(key, value);
 */

pub struct LRUCache {
    cache: Vec<(i32, i32)>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LRUCache {
    pub fn new(capacity: i32) -> Self {
        Self {
            cache: (0..capacity).map(|_| (-1, -1)).collect(),
        }
    }

    pub fn get(&mut self, key: i32) -> i32 {
        if let Some(index) = self.cache.iter().position(|&(k, _)| k == key) {
            self.cache[0..=index].rotate_right(1);
            self.cache[0].1
        } else {
            -1
        }
    }

    pub fn put(&mut self, key: i32, value: i32) {
        if let Some(index) = self.cache.iter().position(|&(k, _)| k == key) {
            self.cache[index].1 = value;
            self.cache[..=index].rotate_right(1);
        } else {
            self.cache.rotate_right(1);
            self.cache[0] = (key, value);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * let obj = LRUCache::new(capacity);
 * let ret_1: i32 = obj.get(key);
 * obj.put(key, value);
 */

pub struct LRUCache {
    cache: Box<[(i32, i32)]>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LRUCache {
    pub fn new(capacity: i32) -> Self {
        Self {
            cache: (0..capacity)
                .map(|_| (-1, -1))
                .collect::<Vec<_>>()
                .into_boxed_slice(),
        }
    }

    pub fn get(&mut self, key: i32) -> i32 {
        if let Some(index) = self.cache.iter().position(|&(k, _)| k == key) {
            self.cache[0..=index].rotate_right(1);
            self.cache[0].1
        } else {
            -1
        }
    }

    pub fn put(&mut self, key: i32, value: i32) {
        if let Some(index) = self.cache.iter().position(|&(k, _)| k == key) {
            self.cache[index].1 = value;
            self.cache[..=index].rotate_right(1);
        } else {
            self.cache.rotate_right(1);
            self.cache[0] = (key, value);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * let obj = LRUCache::new(capacity);
 * let ret_1: i32 = obj.get(key);
 * obj.put(key, value);
 */
use std::collections::HashMap;

struct Node {
    value: i32,
    prev: Option<i32>,
    next: Option<i32>,
}

pub struct LRUCache {
    capacity: usize,
    first: Option<i32>,
    last: Option<i32>,
    map: HashMap<i32, Node>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LRUCache {
    pub fn new(capacity: i32) -> Self {
        Self {
            capacity: capacity as usize,
            first: None,
            last: None,
            map: HashMap::new(),
        }
    }

    pub fn get(&mut self, key: i32) -> i32 {
        if let Some(value) = self.remove(&key) {
            self.put(key, value);
            value
        } else {
            -1
        }
    }

    pub fn put(&mut self, key: i32, value: i32) {
        self.remove(&key);

        if self.map.len() == self.capacity {
            self.remove(&self.last.unwrap());
        }

        self.map.insert(
            key,
            Node {
                value,
                prev: None,
                next: self.first,
            },
        );

        match self.first {
            None => self.last = Some(key),
            Some(k) => self.map.get_mut(&k).unwrap().prev = Some(key),
        }

        self.first = Some(key);
    }

    pub fn remove(&mut self, key: &i32) -> Option<i32> {
        if let Some(node) = self.map.remove(key) {
            match &node.prev {
                None => self.first = node.next,
                Some(k) => self.map.get_mut(k).unwrap().next = node.next,
            };

            match &node.next {
                None => self.last = node.prev,
                Some(k) => self.map.get_mut(k).unwrap().prev = node.prev,
            };

            Some(node.value)
        } else {
            None
        }
    }
}
