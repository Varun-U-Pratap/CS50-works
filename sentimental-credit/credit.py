sum = 0
while True:
    card = input("Number: ")
    if card.isnumeric():
        break
for i in range(1, len(card) + 1):
    if (i - 1) % 2 == 0:
        sum = sum + (int)(card[len(card) - i])
    else:
        sum = sum + (((int)(card[len(card) - i]))*2) % 10
        sum = sum + ((int)((((int)(card[len(card) - i]))*2)/10))
if (sum % 10 != 0) or (len(card) < 13 or len(card) > 16):
    print("INVALID")
elif card[0] == "4":
    print("VISA")
elif card[0] == "3" and (card[1] == "4" or card[1] == "7"):
    print("AMEX")
elif card[0] == "5" and (int)(card[1]) in range(1, 6):
    print("MASTERCARD")
else:
    print("INVALID")
