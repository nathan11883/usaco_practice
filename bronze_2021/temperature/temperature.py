"""
ID: 
LANG: PYTHON3
TASK: temperature
"""

import sys

N = int(sys.stdin.readline().rstrip())
prefer = [int(n) for n in sys.stdin.readline().rstrip().split()]
temperature = [int(n) for n in sys.stdin.readline().rstrip().split()]

delta = [0] * N
adjustQ = []
start = -1
smallest = float('inf')
symbol = 0
for i in range(N):
  delta[i] = prefer[i] - temperature[i]
  flip = False
  if delta[i] < 0:
    if symbol == 0:
      symbol = -1
    elif symbol == 1:
      flip = True 
    delta[i] = delta[i] * -1
  elif delta[i] > 0:
    if symbol == 0:
      symbol = 1
    elif symbol == -1:
      flip = True
  else:
    flip = True
  
  if flip:
    if start + 1 < i:
      adjustQ.append((smallest, delta[start + 1:i]))
      smallest = float('inf')
    start = i
  else:
    if smallest > delta[i]:
      smallest = delta[i]
  print(f"smallest:{smallest}, delta[{i}]={delta[i]}, flip:{flip}")

else:
  if start < N-1:
    adjustQ.append((smallest, delta[start + 1:]))

print(adjustQ)

count = 0
start = -1
smallest = float('inf')
while adjustQ:
  (sm,last) = adjustQ.pop()
  count += sm 
  for j in range(len(last)):
    print(f"last[{j}]={last[j]}, smallest:{smallest}")
    last[j] = last[j] - sm
    if(last[j] == 0):
      if start + 1 < j:
        adjustQ.append((smallest, last[start + 1:j]))
        smallest = float('inf')
      start = j
    else:
      if smallest > last[j]:
        smallest = last[j]
  else:
    if start < len(last)-1:
      adjustQ.append((smallest, last[start + 1:]))

  print(adjustQ)

sys.stdout.write(f'{count}\n')

