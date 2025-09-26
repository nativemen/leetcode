struct Solution;

impl Solution {
    pub fn suggested_products(products: Vec<String>, search_word: String) -> Vec<Vec<String>> {
        let mut products = products;
        products.sort();

        let mut result = Vec::new();
        let mut prefix = String::new();
        let search_word = search_word.as_bytes();
        let word_size = search_word.len();
        let products_size = products.len();

        for i in 0..word_size {
            let mut matched = Vec::new();
            prefix.push(search_word[i] as char);

            for j in 0..products_size {
                if products[j].starts_with(prefix.as_str()) {
                    matched.push(products[j].clone());
                    if matched.len() >= 3 {
                        break;
                    }
                }
            }

            result.push(matched);
        }

        result
    }
}

impl Solution {
    pub fn suggested_products(products: Vec<String>, search_word: String) -> Vec<Vec<String>> {
        let mut products = products;
        products.sort();

        let mut result = Vec::new();
        let products_size = products.len();
        let mut left = 0;
        let mut right = products_size - 1;

        for (i, c) in search_word.chars().enumerate() {
            while left <= right
                && (products[left].len() <= i || products[left].chars().nth(i) != Some(c))
            {
                left += 1;
            }

            while left <= right
                && (products[right].len() <= i || products[right].chars().nth(i) != Some(c))
            {
                right -= 1;
            }

            let remain = right - left + 1;
            let mut matched = Vec::new();

            for j in 0..remain.min(3) {
                matched.push(products[left + j].clone());
            }

            result.push(matched);
        }

        result
    }
}

impl Solution {
    pub fn suggested_products(products: Vec<String>, search_word: String) -> Vec<Vec<String>> {
        let mut products = products;
        products.sort();

        let mut result = Vec::new();
        let search_word = search_word.as_bytes();
        let products_size = products.len();
        let mut left = 0;
        let mut right = products_size;

        for i in 0..search_word.len() {
            while left < right
                && (products[left].len() <= i || products[left].as_bytes()[i] != search_word[i])
            {
                left += 1;
            }

            while left < right
                && (products[right - 1].len() <= i
                    || products[right - 1].as_bytes()[i] != search_word[i])
            {
                right -= 1;
            }

            result.push(
                products[left..right.min(left + 3)]
                    .iter()
                    .map(|x| x.to_string())
                    .collect::<Vec<_>>(),
            );
        }

        result
    }
}
