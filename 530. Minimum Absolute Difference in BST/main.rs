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
    fn inorder(root: &Option<Rc<RefCell<TreeNode>>>, minDifference: &mut i32, prevValue: &mut i32) {
        if let Some(node) = root {
            let node_ref = node.borrow_mut();

            Self::inorder(&node_ref.left, minDifference, prevValue);

            if *prevValue >= 0 {
                *minDifference = (*minDifference).min(node_ref.val - *prevValue);
            }

            *prevValue = node_ref.val;

            Self::inorder(&node_ref.right, minDifference, prevValue);
        }
    }

    pub fn get_minimum_difference(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut minDifference = i32::MAX;
        let mut prevValue = -1;

        Self::inorder(&root, &mut minDifference, &mut prevValue);

        minDifference
    }
}
