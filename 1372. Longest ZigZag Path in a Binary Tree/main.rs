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
    pub fn longest_zig_zag(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn zig_zag(
            root: Option<Rc<RefCell<TreeNode>>>,
            go_right: bool,
            steps: i32,
            max_count: &mut i32,
        ) {
            if let Some(node) = root {
                let node_ref = node.borrow();

                if *max_count < steps {
                    *max_count = steps;
                }

                if go_right {
                    zig_zag(node_ref.left.clone(), false, steps + 1, max_count);
                    zig_zag(node_ref.right.clone(), true, 1, max_count);
                } else {
                    zig_zag(node_ref.right.clone(), true, steps + 1, max_count);
                    zig_zag(node_ref.left.clone(), false, 1, max_count);
                }
            }
        }

        let mut max_count = 0;

        if let Some(node) = root {
            let node_ref = node.borrow();

            zig_zag(node_ref.left.clone(), false, 1, &mut max_count);
            zig_zag(node_ref.right.clone(), true, 1, &mut max_count);
        }

        max_count
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
    pub fn longest_zig_zag(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn zig_zag(
            root: Option<Rc<RefCell<TreeNode>>>,
            left: i32,
            right: i32,
            max_count: &mut i32,
        ) {
            if let Some(node) = root {
                let node_ref = node.borrow();

                *max_count = (*max_count).max(left.max(right));

                zig_zag(node_ref.left.clone(), right + 1, 0, max_count);
                zig_zag(node_ref.right.clone(), 0, left + 1, max_count);
            }
        }

        let mut max_count = 0;

        if let Some(node) = root {
            let node_ref = node.borrow();

            zig_zag(node_ref.left.clone(), 1, 0, &mut max_count);
            zig_zag(node_ref.right.clone(), 0, 1, &mut max_count);
        }

        max_count
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
    pub fn longest_zig_zag(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn zig_zag_left(root: Option<Rc<RefCell<TreeNode>>>, steps: i32, max_count: &mut i32) {
            if let Some(node) = root {
                let node_ref = node.borrow();

                *max_count = (*max_count).max(steps);

                zig_zag_right(node_ref.right.clone(), steps + 1, max_count);
                zig_zag_left(node_ref.left.clone(), 1, max_count);
            }
        }

        fn zig_zag_right(root: Option<Rc<RefCell<TreeNode>>>, steps: i32, max_count: &mut i32) {
            if let Some(node) = root {
                let node_ref = node.borrow();

                *max_count = (*max_count).max(steps);

                zig_zag_left(node_ref.left.clone(), steps + 1, max_count);
                zig_zag_right(node_ref.right.clone(), 1, max_count);
            }
        }

        let mut max_count = 0;

        if let Some(node) = root {
            let node_ref = node.borrow();

            zig_zag_left(node_ref.left.clone(), 1, &mut max_count);
            zig_zag_right(node_ref.right.clone(), 1, &mut max_count);
        }

        max_count
    }
}
