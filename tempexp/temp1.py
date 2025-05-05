import re
split = x = input("Enter the math: ")
split = re.split(r'([ +\-/*])',split)
split = [item.strip() for item in split if item.strip()]
print(split)
print(result)
print(result)
