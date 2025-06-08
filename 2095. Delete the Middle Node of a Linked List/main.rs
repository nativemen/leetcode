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
    pub fn delete_middle(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut count = 0;
        let mut head = head;
        let mut current = head.as_ref();

        while let Some(node) = current {
            count += 1;
            current = node.next.as_ref();
        }

        count /= 2;
        let mut current = &mut head;

        for i in 0..count {
            current = &mut current.as_mut()?.next;
        }

        *current = current.as_mut()?.next.take();

        head
    }
}
