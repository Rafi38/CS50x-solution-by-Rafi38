text = input("Text: ").strip()

sen_count = 0
word_count = 1
letter_count = 0
for letter in text:
    if letter == "!" or letter == "?" or letter == ".":    # count sentences
        sen_count += 1
    if letter == " ":       # count words
        word_count += 1
    if letter.isalpha():  # count lettter
        letter_count += 1

L = letter_count / word_count * 100
S = sen_count / word_count * 100

index = 0.0588 * L - 0.296 * S - 15.8

if index < 16 and index >= 0:   # final result
    print("Grade", round(index))
elif index >= 16:
    print("Grade 16+")
else:
    print("Before Grade 1")