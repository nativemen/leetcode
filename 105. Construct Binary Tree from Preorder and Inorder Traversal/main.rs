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
    pub fn build_tree(preorder: Vec<i32>, inorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        if preorder.is_empty() || inorder.is_empty() {
            return None;
        }

        if let Some(mid) = inorder.iter().position(|&x| x == preorder[0]) {
            let mut node = TreeNode::new(preorder[0]);
            node.left = Self::build_tree(preorder[1..mid + 1].to_vec(), inorder[..mid].to_vec());
            node.right =
                Self::build_tree(preorder[mid + 1..].to_vec(), inorder[mid + 1..].to_vec());

            Some(Rc::new(RefCell::new(node)))
        } else {
            None
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
    fn build_node(preorder: &[i32], inorder: &[i32]) -> Option<Rc<RefCell<TreeNode>>> {
        let root_val = preorder.get(0)?;
        let inorder_root_pos = inorder
            .iter()
            .position(|x| x == root_val)
            .expect("inorder contains root!");
        let left_preorder = &preorder[1..inorder_root_pos + 1];
        let left_inorder = &inorder[..inorder_root_pos];
        let right_preorder = &preorder[inorder_root_pos + 1..];
        let right_inorder = &inorder[inorder_root_pos + 1..];
        let left = Self::build_node(left_preorder, left_inorder);
        let right = Self::build_node(right_preorder, right_inorder);

        Some(Rc::new(RefCell::new(TreeNode {
            val: *root_val,
            left,
            right,
        })))
    }

    pub fn build_tree(preorder: Vec<i32>, inorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::build_node(&preorder, &inorder)
    }
}
