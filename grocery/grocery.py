def main():
    items = []
    itemsdic = {}
    while True:
        try:
            item = input().lower()
            items.append(item)
        except EOFError:
            break
    for i in items:
        count = items.count(i)
        itemsdic[i] = count
    print()
    itemsdic = dict(sorted(itemsdic.items()))
    for k in itemsdic:
        print(itemsdic[k], k.upper())

main()
