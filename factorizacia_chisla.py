n = int(input())

def prime_divisors(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            print(i, end=' ')
            n //= i
        else:
            i += 1
    if n > 1:
        print(n)

prime_divisors(n) 
