import re
def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    if not (s[0:2].isalpha()) or not (6 >= len(s) >= 2):
        return False
    for i in s:
        if i in [' ', '.', ',', '']:
            return False
    split = re.split(r"(\d+)", s)
    split = [item.strip() for item in split if item.strip()]
    if len(split) == 2:
        if split[1][0] == '0':
            return False
    elif len(split) > 2:
        return False
    return True

main()
