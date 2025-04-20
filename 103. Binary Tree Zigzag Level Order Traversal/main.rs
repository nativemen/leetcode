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
    pub fn zigzag_level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut result = Vec::new();

        if root.is_none() {
            return result;
        }

        let mut q = vec![root];
        let mut left_to_right = true;

        while !q.is_empty() {
            let size = q.len();
            let mut values = Vec::new();

            for _ in 0..size {
                if let Some(node) = q.remove(0) {
                    let node_ref = node.borrow();

                    values.push(node_ref.val);

                    if node_ref.left.is_some() {
                        q.push(node_ref.left.clone());
                    }

                    if node_ref.right.is_some() {
                        q.push(node_ref.right.clone());
                    }
                }
            }

            if !left_to_right {
                values.reverse();
            }

            result.push(values);
            left_to_right = !left_to_right;
        }

        result
    }
}
