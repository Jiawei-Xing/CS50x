from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n in [1, 2, 3, 4, 5, 6, 7, 8]:
        break

for i in range(n):
    print(" " * (n - i - 1) + "#" * (i + 1) + "  " + "#" * (i + 1))