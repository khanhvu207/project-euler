f_1 = 1
f_2 = 1
cnt = 2

while True:
    f_x = f_2 + f_1
    cnt += 1
    if len(str(f_x)) == 1000:
        print(cnt)
        break
    f_1 = f_2
    f_2 = f_x