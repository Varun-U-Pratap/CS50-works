inp = input("Greeting: ").strip().lower()
if inp[:5] == "hello":
    print("$0", end="")
elif inp[0] == "h":
    print("$20", end="")
else:
    print("$100", end="")
