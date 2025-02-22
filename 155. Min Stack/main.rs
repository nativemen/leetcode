const STACK_SIZE: usize = 30000;

struct MinStack {
    val_stack: [i32; STACK_SIZE],
    min_stack: [i32; STACK_SIZE],
    count: usize,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MinStack {
    fn new() -> Self {
        Self {
            val_stack: [0; STACK_SIZE],
            min_stack: [0; STACK_SIZE],
            count: 0,
        }
    }

    fn push(&mut self, val: i32) {
        if self.count >= STACK_SIZE {
            panic!("Stack is full.")
        }

        if self.count == 0 {
            self.min_stack[self.count] = val;
        } else {
            self.min_stack[self.count] = self.min_stack[self.count - 1].min(val);
        }

        self.val_stack[self.count] = val;
        self.count += 1;
    }

    fn pop(&mut self) {
        if self.count == 0 {
            panic!("Stack is empty.")
        }

        self.count -= 1;
    }

    fn top(&self) -> i32 {
        if self.count == 0 {
            panic!("Stack is empty.")
        }

        self.val_stack[self.count - 1]
    }

    fn get_min(&self) -> i32 {
        if self.count == 0 {
            panic!("Stack is empty.")
        }

        self.min_stack[self.count - 1]
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * let obj = MinStack::new();
 * obj.push(val);
 * obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: i32 = obj.get_min();
 */

struct MinStack {
    val_stack: Vec<i32>,
    min_stack: Vec<i32>
}

const STACK_SIZE: i32 = 30000;

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MinStack {

    fn new() -> Self {
        Self {
            val_stack : Vec::new(),
            min_stack : Vec::new(),
        }
    }

    fn push(&self, val: i32) {

    }

    fn pop(&self) {
        if self.val_stack.is_empty() {
            panic!("Stack is empty.")
        }

        self.val_stack.pop();
        self.min_stack.pop();
        self.count -= 1;
    }

    fn top(&self) -> i32 {
        if self.val_stack.is_empty() {
            panic!("Stack is empty.")
        }

        self.val_stack.last().unwrap().to_owned()
    }

    fn get_min(&self) -> i32 {
        if self.val_stack.is_empty() {
            panic!("Stack is empty.")
        }

        self.min_stack.last().unwrap().to_owned()
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * let obj = MinStack::new();
 * obj.push(val);
 * obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: i32 = obj.get_min();
 */


 struct MinStack {
    stack: Vec<(i32, i32)>,
}

const STACK_SIZE: usize = 30000;

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MinStack {
    fn new() -> Self {
        Self {
            stack: Vec::with_capacity(STACK_SIZE),
        }
    }

    fn push(&mut self, val: i32) {
        if self.stack.len() >= STACK_SIZE {
            panic!("Stack is full.")
        }

        if self.stack.is_empty() {
            self.stack.push((val, val));
        } else {
            self.stack.push((val, self.get_min().min(val)));
        }
    }

    fn pop(&mut self) {
        if self.stack.is_empty() {
            panic!("Stack is empty.")
        }

        self.stack.pop();
    }

    fn top(&self) -> i32 {
        if self.stack.is_empty() {
            panic!("Stack is empty.")
        }

        self.stack.last().unwrap().to_owned().0
    }

    fn get_min(&self) -> i32 {
        if self.stack.is_empty() {
            panic!("Stack is empty.")
        }

        self.stack.last().unwrap().to_owned().1
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * let obj = MinStack::new();
 * obj.push(val);
 * obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: i32 = obj.get_min();
 */