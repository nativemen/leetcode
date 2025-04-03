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
    pub fn partition(head: Option<Box<ListNode>>, x: i32) -> Option<Box<ListNode>> {
        let mut dummy1 = ListNode::new(0);
        let mut dummy2 = ListNode::new(0);
        let mut first = &mut dummy1;
        let mut second = &mut dummy2;
        let mut head = head;

        while let Some(mut node) = head {
            head = node.next.take();
            if node.val < x {
                first.next = Some(node);
                first = first.next.as_mut().unwrap();
            } else {
                second.next = Some(node);
                second = second.next.as_mut().unwrap();
            }
        }

        second.next = None;
        first.next = dummy2.next;

        dummy1.next
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
    pub fn partition(head: Option<Box<ListNode>>, x: i32) -> Option<Box<ListNode>> {
        let mut dummy1 = Some(Box::new(ListNode::new(0)));
        let mut dummy2 = Some(Box::new(ListNode::new(0)));
        let mut first = dummy1.as_mut();
        let mut second = dummy2.as_mut();
        let mut head = head;

        while let Some(mut node) = head {
            head = node.next.take();
            if node.val < x {
                if let Some(node1) = first {
                    node1.next = Some(node);
                    first = node1.next.as_mut();
                }
            } else {
                if let Some(node2) = second {
                    node2.next = Some(node);
                    second = node2.next.as_mut();
                }
            }
        }

        if let Some(node2) = second {
            node2.next = None;
        }

        if let Some(node1) = first {
            node1.next = dummy2.unwrap().next;
        }

        dummy1.unwrap().next
    }
}
