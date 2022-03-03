
# Request input
while True:
    try:
        height = int(input("Height: "))
        # Check that number is in range (from 1 including but not 9).
        if height not in range(1, 9):
            continue
        else:
            break
    except:
        continue

for i in range(1, height+1, 1):
    # Print the format including the spaces before the pyramid.
    print(" " * (int(height)-i) + "#" * i + "  " + "#" * i)