inputt = input("What is the Answer to the Great Question of Life, the Universe, and Everything? ").strip().lower()
if inputt == "42":
    print("Yes")
elif inputt == "forty two":
    print("Yes")
elif inputt == "forty-two":
    print("Yes")
else:
    print("No")
