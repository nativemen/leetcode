char *reverseStr(char *s, int k) {
    int len = strlen(s);
    for (int i = 0; i < len; i += 2 * k) {
        int min = k > len - i ? len - i : k;
        for (int j = 0; j < (min + 1) / 2; j++) {
            char temp = s[i + j];
            s[i + j] = s[i + min - 1 - j];
            s[i + min - 1 - j] = temp;
        }
    }

    return s;
}