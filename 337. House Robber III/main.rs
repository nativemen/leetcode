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
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn rob(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let (first, second) = Self::rob_helper(root);

        first.max(second)
    }

    fn rob_helper(root: Option<Rc<RefCell<TreeNode>>>) -> (i32, i32) {
        match root {
            None => (0, 0),
            Some(node) => {
                let left = Self::rob_helper(node.borrow().left.clone());
                let right = Self::rob_helper(node.borrow().right.clone());
                let with_root = node.borrow().val + left.1 + right.1;
                let without_root = left.0.max(left.1) + right.0.max(right.1);

                (with_root, without_root)
            }
        }
    }
}

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
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn rob(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let (first, second) = Self::rob_helper(&root);

        first.max(second)
    }

    fn rob_helper(root: &Option<Rc<RefCell<TreeNode>>>) -> (i32, i32) {
        match root {
            None => (0, 0),
            Some(node) => {
                let left = Self::rob_helper(&node.borrow().left);
                let right = Self::rob_helper(&node.borrow().right);
                let with_root = node.borrow().val + left.1 + right.1;
                let without_root = left.0.max(left.1) + right.0.max(right.1);

                (with_root, without_root)
            }
        }
    }
}
