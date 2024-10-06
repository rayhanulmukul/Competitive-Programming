MAX_N = 10_000_000

# Step 1: Sieve of Eratosthenes to find all primes up to MAX_N
is_prime = [True] * (MAX_N + 1)
is_prime[0] = is_prime[1] = False

for i in range(2, int(MAX_N ** 0.5) + 1):
    if is_prime[i]:
        for j in range(i * i, MAX_N + 1, i):
            is_prime[j] = False

primes = [i for i, prime in enumerate(is_prime) if prime]

# Step 2: Precompute subtractorizations
# We will count the number of subtractorizations for each N <= MAX_N
subtract_count = [0] * (MAX_N + 1)

prime_set = set(primes)
for p1 in primes:
    for p2 in primes:
        if p1 - p2 in prime_set:
            subtract_count[p1] += 1

# Step 3: Prefix sum of the results to handle test cases efficiently
for i in range(1, MAX_N + 1):
    subtract_count[i] += subtract_count[i - 1]

# Step 4: Answer the queries
T = int(input())
for t in range(1, T + 1):
    N = int(input())
    print(f"Case #{t}: {subtract_count[N]}")
