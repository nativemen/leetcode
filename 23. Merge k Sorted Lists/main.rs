struct Solution;

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    fn merge_two_lists(
        list1: Option<Box<ListNode>>,
        list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        match (list1, list2) {
            (None, None) => None,
            (Some(node1), None) => Some(node1),
            (None, Some(node2)) => Some(node2),
            (Some(mut node1), Some(mut node2)) => {
                if node1.val < node2.val {
                    node1.next = Self::merge_two_lists(node1.next, Some(node2));
                    Some(node1)
                } else {
                    node2.next = Self::merge_two_lists(Some(node1), node2.next);
                    Some(node2)
                }
            }
        }
    }

    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        if lists.is_empty() {
            return None;
        }

        let size = lists.len();
        if size == 1 {
            return lists[0].clone();
        }

        let mut lists = lists;
        lists[1] = Self::merge_two_lists(lists[0].take(), lists[1].take());
        lists.remove(0);

        return Self::merge_k_lists(lists);
    }
}

// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    fn merge_two_lists(
        list1: Option<Box<ListNode>>,
        list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        match (list1, list2) {
            (None, None) => None,
            (Some(node1), None) => Some(node1),
            (None, Some(node2)) => Some(node2),
            (Some(mut node1), Some(mut node2)) => {
                if node1.val < node2.val {
                    node1.next = Self::merge_two_lists(node1.next, Some(node2));
                    Some(node1)
                } else {
                    node2.next = Self::merge_two_lists(Some(node1), node2.next);
                    Some(node2)
                }
            }
        }
    }

    fn merge_k_lists_helper(
        lists: &mut Vec<Option<Box<ListNode>>>,
        left: i32,
        right: i32,
    ) -> Option<Box<ListNode>> {
        if left > right {
            return None;
        }

        if left == right {
            return lists[left as usize].take();
        }

        let mid = (left + right) / 2;
        let left_list = Self::merge_k_lists_helper(lists, left, mid);
        let right_list = Self::merge_k_lists_helper(lists, mid + 1, right);

        return Self::merge_two_lists(left_list, right_list);
    }

    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        let mut lists = lists;
        let right = lists.len() as i32 - 1;
        Self::merge_k_lists_helper(&mut lists, 0, right)
    }
}

// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        let mut nodes = Vec::new();
        for list in lists {
            let mut current = list;
            while let Some(mut node) = current {
                current = node.next.take();
                nodes.push(node);
            }
        }

        nodes.sort_by(|a, b| a.val.cmp(&b.val));

        let mut result = None;
        for mut node in nodes.into_iter().rev() {
            node.next = result;
            result = Some(node);
        }

        result
    }
}
