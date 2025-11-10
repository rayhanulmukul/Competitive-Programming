class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        def score(s, x, y):
            stack = []
            total_score = 0
            for char in s:
                if stack and stack[-1] == 'a' and char == 'b':
                    total_score += x
                    stack.pop()
                elif stack and stack[-1] == 'b' and char == 'a':
                    total_score += y
                    stack.pop()
                else:
                    stack.append(char)
            return total_score

        if x > y:
            return score(s, x, y) + score(s[::-1], y, x)
        else:
            return score(s, y, x) + score(s[::-1], x, y)