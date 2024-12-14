impl Solution {
    pub fn check_if_exist(arr: Vec<i32>) -> bool {
        for i in 0..arr.len() {
            for j in i + 1..arr.len() {
                if arr[i] == arr[j] * 2 || arr[j] == arr[i] * 2 {
                    return true;
                }
            }
        }

        return false;
    }
}
