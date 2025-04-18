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
    pub fn build_tree(inorder: Vec<i32>, postorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        if inorder.is_empty() || postorder.is_empty() {
            return None;
        }

        let postorder_size = postorder.len();
        let current = postorder[postorder_size - 1];
        let mid = inorder.iter().position(|x| *x == current).unwrap();
        let right = Self::build_tree(
            inorder[mid + 1..].to_vec(),
            postorder[mid..postorder_size - 1].to_vec(),
        );
        let left = Self::build_tree(inorder[..mid].to_vec(), postorder[..mid].to_vec());

        Some(Rc::new(RefCell::new(TreeNode {
            val: current,
            left,
            right,
        })))
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
    fn build(inorder: &[i32], postorder: &[i32]) -> Option<Rc<RefCell<TreeNode>>> {
        let current = postorder.last()?;
        let mid = inorder
            .iter()
            .position(|x| x == current)
            .expect("inorder contains no current!");
        let inorder_left = &inorder[..mid];
        let inorder_right = &inorder[mid + 1..];
        let postorder_left = &postorder[..mid];
        let postorder_right = &postorder[mid..postorder.len() - 1];
        let right = Self::build(inorder_right, postorder_right);
        let left = Self::build(inorder_left, postorder_left);

        Some(Rc::new(RefCell::new(TreeNode {
            val: *current,
            left,
            right,
        })))
    }

    pub fn build_tree(inorder: Vec<i32>, postorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::build(&inorder, &postorder)
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
use std::collections::HashMap;
use std::rc::Rc;
impl Solution {
    fn build(
        inorder: &[i32],
        postorder: &[i32],
        map: &HashMap<i32, usize>,
        inorder_offset: usize,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let current = postorder.last()?;
        let mid = map[current] - inorder_offset;
        let inorder_left = &inorder[..mid];
        let inorder_right = &inorder[mid + 1..];
        let postorder_left = &postorder[..mid];
        let postorder_right = &postorder[mid..postorder.len() - 1];
        let inorder_offset_left = inorder_offset;
        let inorder_offset_right = mid + inorder_offset + 1;
        let right = Self::build(inorder_right, postorder_right, map, inorder_offset_right);
        let left = Self::build(inorder_left, postorder_left, map, inorder_offset_left);

        Some(Rc::new(RefCell::new(TreeNode {
            val: *current,
            left,
            right,
        })))
    }

    pub fn build_tree(inorder: Vec<i32>, postorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        let map = inorder
            .iter()
            .enumerate()
            .map(|(i, val)| (*val, i))
            .collect();
        Self::build(&inorder, &postorder, &map, 0)
    }
}
