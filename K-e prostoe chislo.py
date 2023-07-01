import math

def bit_sieve(n):
    if n < 2:
        return []
    bits = [1] * n
    sqrt_n = int(math.sqrt(n)) + 1
    for i in range(2, sqrt_n):
        if bits[i - 2]:
            for j in range (i + i, n + 1, i):
                bits[j - 2] = 0
    return bits

def foo():
    n = input()
    if n == '0':
        return

    arr = map(int, input().split())
    max = 100000
    sieve = bit_sieve(int(1.5 * max * math.log(max)) + 1)
    dict = { }

    j = 0
    k = 1
    for i in sieve:
        j += 1
        if (i):
            dict[k] = j + 1
            k += 1

    for k in arr:
        yield dict[k]

print(*foo())