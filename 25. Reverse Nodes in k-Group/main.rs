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
    fn reverse_k_list(nodes: &mut Vec<Box<ListNode>>, k: usize) {
        for chunk in nodes.chunks_mut(k) {
            if chunk.len() == k {
                chunk.reverse();
            }
        }
    }

    pub fn reverse_k_group(head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        let mut nodes = Vec::new();
        let mut current = head;

        while let Some(mut node) = current {
            current = node.next.take();
            nodes.push(node);
        }

        Self::reverse_k_list(&mut nodes, k as usize);
        nodes.reverse();

        let mut new_head = None;
        for mut node in nodes {
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
    pub fn reverse_k_group(head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        if head.is_none() || k <= 1 {
            return head;
        }

        let mut current = &head;
        let mut count = 0;

        while let Some(node) = current {
            current = &node.next;
            count += 1;
        }

        let mut next = head;
        let mut head = None;
        let mut group_first = &mut head;

        for _ in 0..count / k {
            let mut prev = None;

            for _ in 0..k {
                let mut current = next;
                next = current.as_mut().unwrap().next.take();
                current.as_mut().unwrap().next = prev.take();
                prev = current;
            }

            *group_first = prev.take();
            while let Some(node) = group_first {
                group_first = &mut node.next;
            }
        }

        *group_first = next.take();

        head
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
    pub fn reverse_k_group(head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        let mut nodes = Vec::new();
        let mut current = head;

        while let Some(mut node) = current {
            current = node.next.take();
            nodes.push(node);
        }

        let k = k as usize;
        nodes.chunks_exact_mut(k as usize).for_each(|chunk| {
            for i in 0..k / 2 {
                chunk.swap(i, k - i - 1);
            }
        });

        let mut new_head = None;
        let mut current = &mut new_head;
        for node in nodes {
            current = &mut current.insert(node).next;
        }

        new_head
    }
}
