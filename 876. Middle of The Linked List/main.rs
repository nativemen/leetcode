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
    pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut middle = head.as_ref();
        let mut end = head.as_ref();
        while (end != None && end.unwrap().next != None) {
            middle = middle.unwrap().next.as_ref();
            end = end.unwrap().next.as_ref().unwrap().next.as_ref();
        }

        Some(middle?.clone())
    }
}

impl Solution {
    pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut middle = head.as_ref();
        let mut end = head.as_ref();
        while let Some(current) = end {
            if let Some(next) = current.next.as_ref() {
                middle = middle.unwrap().next.as_ref();
                end = next.next.as_ref();
            } else {
                break;
            }
        }

        Some(middle?.clone())
    }
}

impl Solution {
    /// Returns the middle node of a linked list using end/middle pointer technique
    /// Time: O(n), Space: O(1)
    pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut middle = &head;
        let mut end = &head;

        while end.as_ref().and_then(|node| node.next.as_ref()).is_some() {
            middle = &middle.as_ref()?.next;
            end = &end.as_ref()?.next.as_ref()?.next;
        }

        middle.clone()
    }
}

impl Solution {
    /// Returns the middle node using end/middle pointer technique
    /// Time: O(n), Space: O(1)
    pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let (mut middle, mut end) = (head.as_ref(), head.as_ref());

        while let Some(node) = end.and_then(|n| n.next.as_ref()) {
            middle = middle?.next.as_ref();
            end = node.next.as_ref();
        }

        middle.cloned()
    }
}
