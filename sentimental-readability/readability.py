string = input("Text: ")
letters = 0
words = 0
sentence = 0
for char in string:
    if char.isalpha():
        letters += 1
    if char == " ":
        words += 1
    if char == "!" or char == "." or char == "?":
        sentence += 1
index = 0.0588 * ((letters / (words + 1))*100) - 0.296 * ((sentence / (words + 1))*100) - 15.8
if round(index) < 1:
    print("Before Grade 1")
elif round(index) > 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")
