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
    pub fn reverse_between(
        head: Option<Box<ListNode>>,
        left: i32,
        right: i32,
    ) -> Option<Box<ListNode>> {
        let mut values = Vec::new();
        let mut new_head = head.clone();
        let mut current = new_head.as_mut();

        while let Some(node) = current {
            values.push(node.val);
            current = node.next.as_mut();
        }

        for i in (left - 1) as usize..((left + right) / 2) as usize {
            values.swap(i, left as usize + right as usize - 2 - i);
        }

        let mut index = 0;
        current = new_head.as_mut();
        while let Some(node) = current {
            node.val = values[index];
            index += 1;
            current = node.next.as_mut();
        }

        new_head
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
    pub fn reverse_between(
        head: Option<Box<ListNode>>,
        left: i32,
        right: i32,
    ) -> Option<Box<ListNode>> {
        let mut nodes = Vec::new();
        let mut current = head;

        while let Some(mut node) = current {
            current = node.next.take();
            nodes.push(node);
        }

        for i in (left - 1) as usize..((left + right) / 2) as usize {
            nodes.swap(i, left as usize + right as usize - 2 - i);
        }

        let mut new_head = None;
        while let Some(mut node) = nodes.pop() {
            node.next = new_head;
            new_head = Some(node);
        }

        new_head
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
    pub fn list_to_vec(head: Option<Box<ListNode>>) -> Vec<Box<ListNode>> {
        let mut vec = Vec::new();
        let mut current = head;

        while let Some(mut node) = current {
            current = node.next.take();
            vec.push(node);
        }

        vec
    }

    pub fn swap(nodes: &mut Vec<Box<ListNode>>, left: usize, right: usize) {
        for i in left..(left + right + 2) / 2 {
            nodes.swap(i, left + right - i);
        }
    }

    pub fn vec_to_list(mut nodes: Vec<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut head = None;

        while let Some(mut node) = nodes.pop() {
            node.next = head.take();
            head = Some(node);
        }

        head
    }

    pub fn reverse_between(
        head: Option<Box<ListNode>>,
        left: i32,
        right: i32,
    ) -> Option<Box<ListNode>> {
        let mut nodes = Solution::list_to_vec(head);

        Solution::swap(nodes.as_mut(), left as usize - 1, right as usize - 1);
        Solution::vec_to_list(nodes)
    }
}
