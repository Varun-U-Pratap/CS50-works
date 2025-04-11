def main():
    ...
    time = input("What time is it? ")
    tim = convert(time)
    if (7.00 <= tim <= 8.00):
        print("breakfast time")
    elif (12.00 <= tim <= 13.00):
        print("lunch time")
    elif (18.00 <= tim <= 19.00):
        print("dinner time")

def convert(time):
    ...
    time = time.split(":")
    time[0] = float(time[0])
    time[1] = float(time[1])
    return (time[0] + (time[1]/60))


if __name__ == "__main__":
    main()
