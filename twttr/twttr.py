inp = input("Input: ").strip()
for i in inp:
    if i.lower() in ['a', 'e', 'i', 'o', 'u']:
        inp = inp.replace(i,"")
print(inp, end="")
