import sys
import csv


def main():

    # input database and sequence
    if len(sys.argv) != 3:
        print("Usage: python dna.py DATABASE SEQUENCE")

    # find each STR in sequence
    with open(sys.argv[1], 'r') as f1:
        database = list(csv.DictReader(f1))
        result = {}
        for STR in database[0]:
            if STR != "name":
                result[STR] = find_STR(STR)

    # find possible person
    find = 0
    for person in database:
        flag = 1
        for STR in result:
            if result[STR] != int(person[STR]):
                flag = 0
                break
        if flag:
            find = 1
            print(person["name"])
            break

    if find == 0:
        print("No match")


def find_STR(STR):

    # input sequence
    with open(sys.argv[2], 'r') as f2:
        sequence = f2.readline()

    # count consecutive STR
    position = []
    for i in range(len(sequence)-len(STR)):
        if sequence[i:i+len(STR)] == STR:
            tmp = 1
            j = i
            while True:
                j += len(STR)
                if sequence[j:j+len(STR)] == STR:
                    tmp += 1
                else:
                    break
            position.append(tmp)
        else:
            position.append(0)

    return max(position)


if __name__ == "__main__":
    main()
