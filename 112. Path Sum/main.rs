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
    pub fn has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> bool {
        let mut target_sum = target_sum;

        if let Some(node) = root {
            let mut node_ref = node.borrow_mut();

            target_sum -= node_ref.val;

            if node_ref.left.is_none() && node_ref.right.is_none() {
                return target_sum == 0;
            }

            return Self::has_path_sum(node_ref.left.take(), target_sum)
                || Self::has_path_sum(node_ref.right.take(), target_sum);
        } else {
            false
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
    pub fn has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> bool {
        return Self::helper(root, target_sum, 0);
    }

    fn helper(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32, currentSum: i32) -> bool {
        let mut currentSum = currentSum;

        if let Some(node) = root {
            let mut node_ref = node.borrow_mut();

            currentSum += node_ref.val;

            if node_ref.left.is_none() && node_ref.right.is_none() {
                return target_sum == currentSum;
            }

            return Self::helper(node_ref.left.take(), target_sum, currentSum)
                || Self::helper(node_ref.right.take(), target_sum, currentSum);
        } else {
            false
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
    pub fn has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> bool {
        let mut target_sum = target_sum;

        if let Some(node) = root {
            let mut node_ref = node.borrow_mut();

            target_sum -= node_ref.val;

            if node_ref.left.is_none() && node_ref.right.is_none() {
                return target_sum == 0;
            }

            if node_ref.left.is_none() {
                return Self::has_path_sum(node_ref.right.take(), target_sum);
            }

            if node_ref.right.is_none() {
                return Self::has_path_sum(node_ref.left.take(), target_sum);
            }

            return Self::has_path_sum(node_ref.left.take(), target_sum)
                || Self::has_path_sum(node_ref.right.take(), target_sum);
        } else {
            false
        }
    }
}
