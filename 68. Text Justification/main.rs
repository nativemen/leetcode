struct Solution;

impl Solution {
    pub fn full_justify(words: Vec<String>, max_width: i32) -> Vec<String> {
        let mut result = Vec::new();

        let words_count = words.len();
        let mut end = 0;

        while end < words_count {
            let mut start = end;
            let mut line_len = 0;

            while end < words_count
                && line_len + words[end].len() + end - start <= max_width as usize
            {
                line_len += words[end].len();
                end += 1;
            }

            let mut line_str = String::new();
            let space_slots = end - start - 1;
            let remain_spaces = max_width as usize - line_len;
            if end == words_count || space_slots == 0 {
                for i in start..end {
                    line_str.push_str(words[i].as_str());
                    if i < end - 1 {
                        line_str.push_str(" ");
                    }
                }

                line_str.push_str(" ".repeat(max_width as usize - line_str.len()).as_str());
            } else {
                let base_spaces = remain_spaces / space_slots;
                let extra_spaces = remain_spaces % space_slots;

                for i in start..end {
                    line_str.push_str(words[i].as_str());
                    if i < end - 1 {
                        let current_spaces = if i - start < extra_spaces {
                            base_spaces + 1
                        } else {
                            base_spaces
                        };
                        line_str.push_str(" ".repeat(current_spaces).as_str());
                    }
                }
            }

            result.push(line_str);
        }

        result
    }
}

impl Solution {
    fn left_right_justify(row: &Vec<String>, max_width: usize) -> String {
        let mut line_str = String::new();
        let words_num = row.len();
        let words_len = row.iter().map(|word| word.len()).sum::<usize>();
        let space_slots = words_num - 1;
        let remain_spaces = max_width - words_len;

        if space_slots == 0 {
            line_str.push_str(row[0].as_str());
            line_str.push_str(" ".repeat(remain_spaces).as_str());

            return line_str;
        }

        let base_spaces = remain_spaces / space_slots;
        let extra_spaces = remain_spaces % space_slots;

        for (i, word) in row.iter().enumerate() {
            line_str.push_str(word);
            if i < words_num - 1 {
                let current_spaces = if i < extra_spaces {
                    base_spaces + 1
                } else {
                    base_spaces
                };
                line_str.push_str(" ".repeat(current_spaces).as_str());
            }
        }

        line_str
    }

    fn left_justify(row: &Vec<String>, max_width: usize) -> String {
        let mut line_str = row.join(" ");

        line_str.push_str(" ".repeat(max_width - line_str.len()).as_str());

        line_str
    }

    pub fn full_justify(words: Vec<String>, max_width: i32) -> Vec<String> {
        let max_width = max_width as usize;
        let mut result = Vec::new();
        let mut rows = Vec::new();
        let mut row = Vec::new();
        let mut row_len = 0;

        for word in words {
            let length = word.len();
            if row_len + length <= max_width {
                row.push(word);
                row_len += length + 1;
            } else {
                rows.push(row);
                row = Vec::new();
                row.push(word);
                row_len = length + 1;
            }
        }

        if !row.is_empty() {
            rows.push(row);
        }

        let rows_num = rows.len();
        for i in 0..rows_num - 1 {
            result.push(Self::left_right_justify(&rows[i], max_width));
        }

        result.push(Self::left_justify(&rows[rows_num - 1], max_width));

        result
    }
}
