# Readability in Python

# Request input
s = input("Text: ")
words = 0
phrases = 0
chars = 0

for i in s:
    # Count phrases
    if i in ["?", "!", "."]:
        phrases += 1
    # Count characters
    elif i.isalpha():
        chars += 1

# Split input and get length of list.
words = len(s.split())


L = (chars / words) * 100
S = (phrases / words) * 100
index = round(0.0588 * L - 0.296 * S - 15.8)

if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")
