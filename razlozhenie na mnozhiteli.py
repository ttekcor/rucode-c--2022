def factorize(num, min_factor):
    if num == 1:
        return [[]]
    res = []
    for i in range(min_factor, num + 1):
        if num % i == 0:
            sub_res = factorize(num//i, i)
            for sr in sub_res:
                res.append([i] + sr)
    return res

n, m = map(int, input().split())
res = sorted(factorize(n, m))

for r in res:
    print('*'.join(list(map(str, r))))