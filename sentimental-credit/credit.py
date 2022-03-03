import sys

# Prompt for input
cc = input("Number: ")
l = len(cc)
cnt = 0
norm = 0
tot = 0

# Checksum function


def checksum(cc, cnt, norm):
    # 16 digits cards have their first digit as a counter
    if l == 16:
        for i in range(0, l, 1):
            # Therefore, all even places are the counters
            if i % 2 == 0:
                # Compute whether the product is higher than 9
                if int(cc[i]) * 2 > 9:
                    ex = int(cc[i]) * 2
                    # Convert to string to extract each number then back to int
                    cnt += int(str(ex)[0])
                    cnt += int(str(ex)[1])

                else:
                    cnt += int(cc[i]) * 2

            else:
                # normal places
                norm += int(cc[i])

    else:
        for i in range(0, l, 1):
            # In this case, the odd places are the counters
            if i % 2 != 0:

                if int(cc[i]) * 2 > 9:
                    ex = int(cc[i]) * 2
                    cnt += int(str(ex)[0])
                    cnt += int(str(ex)[1])

                else:
                    cnt += int(cc[i]) * 2

            else:
                norm += int(cc[i])

    tot = norm + cnt
    return tot


if l not in range(13, 17):
    print("INVALID")
    sys.exit(1)
else:
    checksum(cc, cnt, norm)

if tot % 10 != 0:
    print("INVALID")
    sys.exit(1)
else:
    if int(cc[:2]) in [51, 52, 53, 54, 55]:
        print("MASTERCARD")

    elif int(cc[0]) == 4:
        print("VISA")

    elif int(cc[:2]) in [34, 37]:
        print("AMEX")

    else:
        print("INVALID")

sys.exit(0)