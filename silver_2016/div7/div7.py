"""
ID: nathand6
LANG: PYTHON3
TASK: subseq
"""
root_path="./silver_2016/div7/"
# When you run locally in replit, comment out the following line.
root_path = ""
cows = []
with open( f"{root_path}div7.in") as fr:
    cows = [int(line.rstrip()) for line in fr]
cow_num = int(cows.pop(0))

largest_group = 0
remainder = 0
last = [-1] * 7
print(last)
print(cows)
for i in range(cow_num):
  print(i)
  remainder = ( remainder + cows[i]) % 7
  print(remainder)
  if (last[remainder] == -1):
    last[remainder] = i
  else:
    largest_group = max(largest_group, i - last[remainder])

x = open(f"{root_path}div7.out", "w")
x.write(f"{largest_group}\n")
x.close()

"""
Passed.
""" 
