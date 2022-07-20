import random

MAX_TEST_CASES = 3000

cases = set()

while len(cases) < MAX_TEST_CASES:
  random_size = random.randint(1,14)
  generated_input = "R"
  for _ in range(random_size):
    generated_input += random.choice(["R", "G", "B"])
  cases.add(generated_input)

for c in cases:
  print(c)