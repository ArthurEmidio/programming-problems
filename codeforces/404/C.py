n, m = [int(x) for x in input().split()]

if n <= m:
    print(n)
else:
    left = int(0)
    right = int(1e10)

    while left < right:
        x = (left + right) // 2

        res = n + m*x - ((x + m + 1)*(x + m + 2) - m*(m + 1))//2

        if res <= 0:
            right = x;
        else:
            left = x + 1;

    print(left + m + 1)
