class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = list()
        words = path.split(sep="/")

        for word in words:
            if word == "..":
                if len(stack) != 0:
                    stack.pop()
            else:
                if word != "" and word != ".":
                    stack.append(word)

        result = ""
        for word in stack:
            result += "/"
            result += word

        if len(stack) == 0:
            result += "/"

        return result


class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = list()
        words = path.split(sep="/")

        for word in words:
            if word == "..":
                if stack:
                    stack.pop()
            else:
                if word and word != ".":
                    stack.append(word)

        result = ""
        for word in stack:
            result += "/"
            result += word

        if len(stack) == 0:
            result += "/"

        return result


class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = list()
        words = path.split(sep="/")

        for word in words:
            if word == "..":
                if stack:
                    stack.pop()
            else:
                if word and word != ".":
                    stack.append(word)

        return "/" + "/".join(stack)
