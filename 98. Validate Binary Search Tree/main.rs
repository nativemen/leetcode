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
    pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let mut v = Vec::new();
        Self::to_vec(&mut v, root);
        for i in 1..v.len() {
            if v[i - 1] >= v[i] {
                return false;
            }
        }

        true
    }

    fn to_vec(v: &mut Vec<i32>, root: Option<Rc<RefCell<TreeNode>>>) {
        match root {
            None => (),
            Some(node) => {
                let node_ref = node.borrow();
                Self::to_vec(v, node_ref.left.clone());
                v.push(node_ref.val);
                Self::to_vec(v, node_ref.right.clone());
                ()
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
    pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Self::helper(root, i64::MIN, i64::MAX)
    }

    fn helper(root: Option<Rc<RefCell<TreeNode>>>, min: i64, max: i64) -> bool {
        match root {
            None => true,
            Some(node) => {
                let node_ref = node.borrow();
                if node_ref.val as i64 <= min || node_ref.val as i64 >= max {
                    return false;
                }

                Self::helper(node_ref.left.clone(), min, node_ref.val as i64)
                    && Self::helper(node_ref.right.clone(), node_ref.val as i64, max)
            }
        }
    }
}
