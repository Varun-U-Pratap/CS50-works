import re
def main():
    month = [
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
        ]
    real = {}
    while True:
        inp = input("Date: ")
        try:
            date = re.split(r'[/]', inp)
            date = [item.strip() for item in date if item.strip()]
            if not (1 <= int(date[1]) <= 30) or not (1 <= int(date[0]) <= 12) or not (1000 <= int(date[2]) <= 3000):
                continue
            real["m"] = int(date[0])
            real["d"] = int(date[1])
            real["y"] = int(date[2])
            break
        except (IndexError, ValueError, EOFError):
                try:
                    date = re.split(r'[ ,]', inp)
                    date = [item.strip() for item in date if item.strip()]
                    if not (1 <= int(date[1]) <= 30) or not (1000 <= int(date[2]) <= 3000) or ',' not in inp:
                        continue
                    try:
                        real["m"] = month.index(str(date[0])) + 1
                        real["d"] = int(date[1])
                        real["y"] = int(date[2])
                        break
                    except (IndexError, ValueError, NameError):
                        continue
                except (IndexError, ValueError, NameError):
                    continue
    print(f"{real["y"]:04}-{real["m"]:02}-{real["d"]:02}")
main()
