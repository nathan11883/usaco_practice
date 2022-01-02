"""
ID: 
LANG: PYTHON3
TASK: single
"""

import sys

N = int(sys.stdin.readline().rstrip())
cows = sys.stdin.readline().rstrip()

g_presum = [0] * len(cows)
h_presum = [0] * len(cows)

gsum = 0
hsum = 0

for c in range(len(cows)):
  if(cows[c] == 'H'):
    hsum += 1
  else:
    gsum += 1

  h_presum[c] = hsum
  g_presum[c] = gsum

print(h_presum)
print(g_presum)

total = 0
left = 0
while left < len(cows):
  right = left + 2
  print(f"left:{left}, right:{right}")
  while right < len(cows):
    print(f"right:{right}")
    h_count = 0
    g_count = 0
    if left == 0:
      h_count = h_presum[right]
      g_count = g_presum[right]
    else:
      h_count = h_presum[right] - h_presum[left-1]
      g_count = g_presum[right] - g_presum[left-1]
    print(f"h_count:{h_count} g_count:{g_count}")
    if h_count == 1 or g_count == 1:
      total += 1
      right += 1
    elif h_count > 1 and g_count > 1:
      
      break
    else:
      right += 1
  left += 1

sys.stdout.write(f'{total}\n')
    

