use std::collections::HashMap;

struct WordDictionary {
    children: HashMap<char, WordDictionary>,
    is_end_of_word: bool,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl WordDictionary {
    fn new() -> Self {
        Self {
            children: HashMap::new(),
            is_end_of_word: false,
        }
    }

    fn add_word(&mut self, word: String) {
        let mut node = self;

        for c in word.chars() {
            if !node.children.contains_key(&c) {
                node.children.entry(c).or_insert(WordDictionary::new());
            }
            node = node.children.get_mut(&c).unwrap();
        }

        node.is_end_of_word = true;
    }

    fn search(&self, word: String) -> bool {
        let mut node = self;

        for (i, c) in word.chars().enumerate() {
            if c == '.' {
                for wd in node.children.values() {
                    if wd.search(word[i + 1..].to_string()) {
                        return true;
                    }
                }

                return false;
            }

            if !node.children.contains_key(&c) {
                return false;
            }
            node = &node.children[&c];
        }

        return node.is_end_of_word;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * let obj = WordDictionary::new();
 * obj.add_word(word);
 * let ret_2: bool = obj.search(word);
 */