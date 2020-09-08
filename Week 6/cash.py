while True:
    change = input("Change owed: ")    # take input
    try:
        change = float(change)    # try to convert to float
        if change < 0:      # if negative, re-prompt for input
            continue
        break        # if satisfied, break the loop
    except:
        continue    # if non-digit input, re-prompt for input
change = change * 100

cash = [25, 10, 5, 1]
count = 0
i = 0
while i <= 3:
    if change >= cash[i]:
        change = change - cash[i]
        count += 1
    else:
        i += 1
        
print(count)