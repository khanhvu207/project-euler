coins = [1, 2, 5, 10, 20, 50, 100, 200]
dp = [0 for _ in range(205)]

dp[0] = 1
x = 200
for i in coins:
    for j in range(i, x + 1):
        dp[j] += dp[j - i]

print(dp[x])