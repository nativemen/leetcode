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
    pub fn leaf_similar(
        root1: Option<Rc<RefCell<TreeNode>>>,
        root2: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        fn dfs(root: Option<Rc<RefCell<TreeNode>>>, array: &mut Vec<i32>) {
            if let Some(node) = root {
                let node_ref = node.borrow();
                if node_ref.left.is_none() && node_ref.right.is_none() {
                    array.push(node_ref.val);
                    return;
                }

                dfs(node_ref.left.clone(), array);
                dfs(node_ref.right.clone(), array);
            }
        }

        let mut array1 = Vec::new();
        let mut array2 = Vec::new();

        dfs(root1, &mut array1);
        dfs(root2, &mut array2);

        array1 == array2
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
    pub fn leaf_similar(
        root1: Option<Rc<RefCell<TreeNode>>>,
        root2: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        fn dfs(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
            let mut result = Vec::new();

            if let Some(node) = root {
                let node_ref = node.borrow();
                if node_ref.left.is_none() && node_ref.right.is_none() {
                    result.push(node_ref.val);
                } else {
                    if node_ref.left.is_some() {
                        result.append(dfs(node_ref.left.clone()).as_mut());
                    }
                    if node_ref.right.is_some() {
                        result.append(dfs(node_ref.right.clone()).as_mut());
                    }
                }
            }

            result
        }

        dfs(root1) == dfs(root2)
    }
}
