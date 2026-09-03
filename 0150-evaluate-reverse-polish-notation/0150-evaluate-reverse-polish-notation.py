class Solution:

    def evalRPN(self, tokens: List[str]) -> int:

        n = len(tokens)

        stack = []

        for s in tokens:   # FIX 1: iterate over tokens, not stack

            if s == '+':

                stack.append(stack.pop() + stack.pop())

            elif s == '-':

                a = stack.pop()
                b = stack.pop()

                stack.append(b - a)

            elif s == '*':

                stack.append(stack.pop() * stack.pop())

            elif s == '/':

                a = stack.pop()   
                b = stack.pop()   

                stack.append(int(b / a)) 
            else:
                stack.append(int(s))
        return stack[-1]   
        