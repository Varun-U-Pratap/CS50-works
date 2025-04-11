import re
inp = input("Date: ")
while True:
    date = re.split(r'[ ,]', inp)
    date = [item.strip() for item in date if item.strip()]
    if not (1 <= int(date[1]) <= 30) or not (1000 <= int(date[2]) <= 3000):
        continue
    try:
        real["m"] = month.index(str(date[0])) + 1
        real["d"] = int(date[1])
        real["y"] = int(date[2])
        break
    except (IndexError, ValueError):
        continue
print(f"{real["y"]:04}-{real["m"]:02}-{real["d"]:02}")
