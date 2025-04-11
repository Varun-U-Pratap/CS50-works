import re
split = x = input("Enter the math: ")
split = re.split(r'([ +\-/*])',split)
split = [item.strip() for item in split if item.strip()]
split[0] = float(split[0])
split[2] = float(split[2])
match split[1]:
    case "+":
        print(split[0]+split[2])
    case "-":
        print(split[0]-split[2])
    case "/":
        print(split[0]/split[2])
    case "*":
        print(split[0]*split[2])
    case _:
          print("Who?")
