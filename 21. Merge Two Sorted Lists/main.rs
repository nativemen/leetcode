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
    pub fn merge_two_lists(
        mut list1: Option<Box<ListNode>>,
        mut list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        if list1 == None {
            return list2;
        }

        if list2 == None {
            return list1;
        }

        let mut dummy = Box::new(ListNode::new(0));
        let mut cur = &mut dummy;
        while list1.is_some() && list2.is_some() {
            let node1 = list1.clone().unwrap();
            let node2 = list2.clone().unwrap();
            if node1.val <= node2.val {
                cur.next = Some(Box::new(ListNode::new(node1.val)));
                list1 = node1.next;
            } else {
                cur.next = Some(Box::new(ListNode::new(node2.val)));
                list2 = node2.next;
            }
            cur = cur.next.as_mut().unwrap();
        }

        cur.next = if list1.is_some() { list1 } else { list2 };

        dummy.next
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
    pub fn merge_two_lists(
        mut list1: Option<Box<ListNode>>,
        mut list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut dummy = ListNode::new(0);
        let mut cur = &mut dummy;

        while let (Some(node1), Some(node2)) = (&list1, &list2) {
            if node1.val <= node2.val {
                cur.next = list1.take();
                cur = cur.next.as_mut().unwrap();
                list1 = cur.next.take();
            } else {
                cur.next = list2.take();
                cur = cur.next.as_mut().unwrap();
                list2 = cur.next.take();
            }
        }

        cur.next = list1.or(list2);
        dummy.next
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
    pub fn merge_two_lists(
        mut list1: Option<Box<ListNode>>,
        mut list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut dummy = ListNode::new(0);
        let mut cur = &mut dummy;

        while let (Some(node1), Some(node2)) = (&list1, &list2) {
            if node1.val <= node2.val {
                std::mem::swap(&mut cur.next, &mut list1);
                cur = cur.next.as_mut().unwrap();
                std::mem::swap(&mut cur.next, &mut list1);
            } else {
                std::mem::swap(&mut cur.next, &mut list2);
                cur = cur.next.as_mut().unwrap();
                std::mem::swap(&mut cur.next, &mut list2);
            }
        }

        cur.next = list1.or(list2);

        dummy.next
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
    pub fn merge_two_lists(
        list1: Option<Box<ListNode>>,
        list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut v1 = Solution::to_vec(list1);
        let mut v2 = Solution::to_vec(list2);
        v1.append(&mut v2);

        v1.sort();

        Solution::from_vec(v1)
    }

    fn to_vec(list: Option<Box<ListNode>>) -> Vec<i32> {
        let mut v = Vec::new();
        let mut list = list;
        while let Some(node) = list {
            v.push(node.val);
            list = node.next;
        }

        v
    }

    fn from_vec(values: Vec<i32>) -> Option<Box<ListNode>> {
        let mut dummy = ListNode::new(0);
        let mut cur = &mut dummy;

        for val in values {
            cur.next = Some(Box::new(ListNode::new(val)));
            cur = cur.next.as_mut().unwrap();
        }

        dummy.next
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
    pub fn merge_two_lists(
        list1: Option<Box<ListNode>>,
        list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        match (list1, list2) {
            (None, None) => None,
            (Some(node1), None) => Some(node1),
            (None, Some(node2)) => Some(node2),
            (Some(mut node1), Some(mut node2)) => {
                if node1.val <= node2.val {
                    node1.next = Self::merge_two_lists(node1.next, Some(node2));
                    Some(node1)
                } else {
                    node2.next = Self::merge_two_lists(Some(node1), node2.next);
                    Some(node2)
                }
            }
        }
    }
}
