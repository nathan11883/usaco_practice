"""
ID: bobsprite
LANG: PYTHON3
TASK: intrv
"""

import sys


intervals =[]
(N,M) = [int(n) for n in sys.stdin.readline().rstrip().split()]
total_len = 2 * M + 1
game = [0] * total_len
result = [0] * total_len
for i in range(N):
  (ai,bi) = [int(n) for n in sys.stdin.readline().rstrip().split()]
  intervals.append((ai,bi))

  for j in range(len(intervals)):
    (aj, bj) = intervals[j]
    if (ai == aj):
      game[ai+aj] += 1
    else:
      game[ai+aj] += 2
    if (bi+bj+1 < total_len):
      if (bi == bj):
        game[bi+bj+1] -= 1
      else:
        game[bi+bj+1] -= 2
total = 0
for i in range(total_len):
  total += game[i]
  result[i] = total
  sys.stdout.write(f"{total}\n")

