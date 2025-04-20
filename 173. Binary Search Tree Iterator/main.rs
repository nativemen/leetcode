struct Solution;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

use std::cell::RefCell;
use std::rc::Rc;

// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
struct BSTIterator {
    array: Vec<TreeNode>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl BSTIterator {
    fn inorder(root: &Option<Rc<RefCell<TreeNode>>>, array: &mut Vec<TreeNode>) {
        if let Some(node) = root {
            let node_ref = node.borrow();
            Self::inorder(&node_ref.left, array);
            array.push(TreeNode {
                val: node_ref.val,
                left: None,
                right: None,
            });
            Self::inorder(&node_ref.right, array);
        }
    }

    fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
        let mut array = Vec::new();

        Self::inorder(&root, &mut array);

        Self { array }
    }

    fn next(&mut self) -> i32 {
        if !self.has_next() {
            return -1;
        }

        self.array.remove(0).val
    }

    fn has_next(&self) -> bool {
        !self.array.is_empty()
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * let obj = BSTIterator::new(root);
 * let ret_1: i32 = obj.next();
 * let ret_2: bool = obj.has_next();
 */


use std::cell::RefCell;
use std::rc::Rc;

// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
struct BSTIterator {
    array: Vec<Rc<RefCell<TreeNode>>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl BSTIterator {
    fn inorder(root: &Option<Rc<RefCell<TreeNode>>>, array: &mut Vec<Rc<RefCell<TreeNode>>>) {
        if let Some(node) = root {
            let node_ref = node.borrow();
            Self::inorder(&node_ref.left, array);
            array.push(node.clone());
            Self::inorder(&node_ref.right, array);
        }
    }

    fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
        let mut array = Vec::new();

        Self::inorder(&root, &mut array);

        Self { array }
    }

    fn next(&mut self) -> i32 {
        if !self.has_next() {
            return -1;
        }

        self.array.remove(0).borrow().val
    }

    fn has_next(&self) -> bool {
        !self.array.is_empty()
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * let obj = BSTIterator::new(root);
 * let ret_1: i32 = obj.next();
 * let ret_2: bool = obj.has_next();
 */

use std::cell::RefCell;
use std::rc::Rc;

// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
struct BSTIterator {
    array: Vec<Rc<RefCell<TreeNode>>>,
    index: usize,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl BSTIterator {
    fn inorder(root: &Option<Rc<RefCell<TreeNode>>>, array: &mut Vec<Rc<RefCell<TreeNode>>>) {
        if let Some(node) = root {
            let node_ref = node.borrow();
            Self::inorder(&node_ref.left, array);
            array.push(node.clone());
            Self::inorder(&node_ref.right, array);
        }
    }

    fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
        let mut array = Vec::new();

        Self::inorder(&root, &mut array);

        Self { array, index: 0 }
    }

    fn next(&mut self) -> i32 {
        if !self.has_next() {
            return -1;
        }

        let value = self.array[self.index].borrow().val;
        self.index += 1;

        value
    }

    fn has_next(&self) -> bool {
        self.index < self.array.len()
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * let obj = BSTIterator::new(root);
 * let ret_1: i32 = obj.next();
 * let ret_2: bool = obj.has_next();
 */