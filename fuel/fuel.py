import re
def main():
    while True:
        try:
            inp = input("Fraction: ")
            inp = re.split(r'[/]', inp)
            fra = round(int(inp[0])*100/int(inp[1]))
            if not 0<= fra <= 100:
                continue
            if fra >= 99:
                print("F")
            elif fra <= 1:
                print("E")
            else:
                print(f"{fra}%")
            break
        except ValueError:
            pass
        except ZeroDivisionError:
            pass
main()
