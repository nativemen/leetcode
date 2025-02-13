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

struct Solution;

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
    pub fn is_symmetric(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let mut v = Vec::new();

        Self::to_vec(&mut v, root, 1);
        let u = v.iter().rev().cloned().collect::<Vec<i32>>();
        v == u
    }

    fn to_vec(v: &mut Vec<i32>, root: Option<Rc<RefCell<TreeNode>>>, layer: i32) {
        const NULL_VAL: i32 = 1 << 8;
        match root {
            None => v.push(NULL_VAL + layer),
            Some(node) => {
                let node_ref = node.borrow();
                Self::to_vec(v, node_ref.left.clone(), layer + 1);
                v.push(node_ref.val);
                Self::to_vec(v, node_ref.right.clone(), layer + 1);
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
    pub fn is_symmetric(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match root {
            None => true,
            Some(node) => {
                let node_ref = node.borrow();
                Self::is_mirror(node_ref.left.clone(), node_ref.right.clone())
            }
        }
    }

    fn is_mirror(
        left: Option<Rc<RefCell<TreeNode>>>,
        right: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        match (left, right) {
            (None, None) => true,
            (Some(_), None) => false,
            (None, Some(_)) => false,
            (Some(left_node), Some(right_node)) => {
                let left_ref = left_node.borrow();
                let right_ref = right_node.borrow();

                left_ref.val == right_ref.val
                    && Self::is_mirror(left_ref.left.clone(), right_ref.right.clone())
                    && Self::is_mirror(left_ref.right.clone(), right_ref.left.clone())
            }
        }
    }
}
