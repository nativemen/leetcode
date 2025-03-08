int lengthOfLastWord(char *s) {
    int count = 0;
    int size = strlen(s);
    char next = ' ';
    for (int i = size - 1; i >= 0; i--) {
        if (next != ' ' && s[i] == ' ') {
            break;
        }

        if (s[i] != ' ') {
            count++;
        }

        next = s[i];
    }

    return count;
}