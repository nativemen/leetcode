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
    fn inorder(root: Option<Rc<RefCell<TreeNode>>>, result: &mut i32, count: &mut i32, k: i32) {
        if let Some(node) = root {
            let node_ref = node.borrow();

            Self::inorder(node_ref.left.clone(), result, count, k);
            *count += 1;
            if *count == k {
                *result = node_ref.val;
                return;
            }
            Self::inorder(node_ref.right.clone(), result, count, k);
        }
    }

    pub fn kth_smallest(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> i32 {
        let mut result = -1;
        let mut count = 0;

        Self::inorder(root, &mut result, &mut count, k);

        result
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
    fn inorder(root: Option<Rc<RefCell<TreeNode>>>, array: &mut Vec<i32>) {
        if let Some(node) = root {
            let node_ref = node.borrow();

            Self::inorder(node_ref.left.clone(), array);
            array.push(node_ref.val);
            Self::inorder(node_ref.right.clone(), array);
        }
    }

    pub fn kth_smallest(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> i32 {
        let mut array = Vec::new();

        Self::inorder(root, &mut array);

        if k < 1 || k > array.len() as i32 {
            return -1;
        }

        array[k as usize - 1]
    }
}
