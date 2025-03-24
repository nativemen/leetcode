struct Solution;

impl Solution {
    pub fn simplify_path(path: String) -> String {
        let mut stack = Vec::new();

        for dir in path.split("/") {
            if dir == ".." {
                stack.pop();
            } else {
                if !dir.is_empty() && dir != "." {
                    stack.push(dir);
                }
            }
        }

        format!("/{}", stack.join("/"))
    }
}

impl Solution {
    pub fn simplify_path(path: String) -> String {
        let mut stack = Vec::new();

        for dir in path.split("/") {
            match dir {
                "" => {
                    continue;
                }
                "." => {
                    continue;
                }
                ".." => {
                    stack.pop();
                }
                s => {
                    stack.push(s);
                }
            }
        }

        format!("/{}", stack.join("/"))
    }
}
