from cs50 import get_string
from re import compile

# input text
text = get_string("Text: ")

# count letters, words, and sentences
letter = 0
word = 1
sentence = 0
l = compile('[a-zA-Z]')

for n in text:
    if l.match(n):
        letter += 1
    elif n == " ":
        word += 1
    elif n == "." or n == "!" or n == "?":
        sentence += 1

# calculate index
grade = round(0.0588 * (letter / word * 100) - 0.296 * (sentence / word * 100) - 15.8)
if grade >= 16:
    print("Grade 16+")
elif grade < 1:
    print("Before Grade 1")
else:
    print("Grade " + str(grade))