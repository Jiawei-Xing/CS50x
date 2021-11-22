from cs50 import get_string
from re import compile

# input card number
def main():
    card = get_string(" Number: ")
    if check_number(card) and check_sum(card):
        card_type = check_type(card)
        print(card_type)
    else:
        print("INVALID")


# check number and length
def check_number(card):
    l13 = compile('^[0-9]{13}$')
    l15 = compile('^[0-9]{15}$')
    l16 = compile('^[0-9]{16}$')
    if l13.match(card) or l15.match(card) or l16.match(card):
        return True
    else:
        return False

# check sum
def check_sum(card):
    sum = 0
    for i in range(len(card)-2, -1, -2):
        tmp = int(card[i]) * 2
        for n in str(tmp):
            sum += int(n)
    for j in range(len(card)-1, -1, -2):
        sum += int(card[j])
    if sum % 10 == 0:
        return True
    else:
        return False

# check type
def check_type(card):
    if len(card) == 15 and (card[:2] == '34' or card[:2] == '37'):
        return "AMEX"
    elif len(card) == 13 and card[0] == '4':
        return "VISA"
    elif len(card) == 16:
        if int(card[:2]) >= 51 and int(card[:2]) <= 55:
            return "MASTERCARD"
        elif card[0] == '4':
            return "VISA"
    else:
        return "INVALID"

if __name__ == "__main__":
    main()
