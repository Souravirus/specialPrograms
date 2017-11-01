d={1:0,2:1}
def modifib(n,d):
   """
   this modified function stores already calcualted fiboanacci number in a dictionary.
   So this reduces the number of calls of modifib() function while recursion. So function reduces probabilty of 
   stack overflow as well as time complexity
   """
   if n in d:
        return d[n]
    else:
        answer=modifib(n-1,d)+modifib(n-2,d)
        d[n]=answer
        return answer

def fib(n):
   """this is general recursive function to find nth fibonacci number.
   It takes quite large time for execution on large inputs
   """
    if n is 1:
        return 0
    elif n is 1 or n is 2:
        return 1
    else:
        return fib(n-1)+fib(n-2)
print(modifib(5,d))
print(fib(5))`
