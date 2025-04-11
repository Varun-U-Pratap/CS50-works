def main():
    due = 50
    while due > 0:
        print(f"Amount Due: {due}")
        inp = int(input("Insert Coin: "))
        if inp in [5,10,25]:
            due -= inp
    print(f"Change Owed: {-due}")
main()
