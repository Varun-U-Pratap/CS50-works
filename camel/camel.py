def main():
    inp = input("camelCase: ")
    print("snake_case: ", end="")
    for _ in inp:
        if _.isupper():
            print("_", end="")
        print(f"{_.lower()}", end="")
    print()
main()
