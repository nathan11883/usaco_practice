"""
ID: 
LANG: PYTHON3
TASK: distinct_path
"""

import sys

T = int(sys.stdin.readline().rstrip())
count = 0
for i in range(T):
  print(f"----- > case {i}")
  total = 0
  (N , K) = [int(n) for n in sys.stdin.readline().rstrip().split()]
  pasture=['']* N
  for j in range(N):
    pasture[j] = sys.stdin.readline().rstrip()
  HP = [[-1 for i in range(2)] for j in range(2)]
  VP = [[-1 for i in range(2)] for j in range(2)]
  print(f"HP: {HP} VP: {VP}")

  if K >= 1:
    print(f"K1: {K}")
    count = 0
    ph = True
    pv = True
    
    HP[0][0] = pasture[0].find("H")
    HP[0][1] = pasture[0].rfind('H')
    HP[1][0] = pasture[N-1].find('H')
    HP[1][1] = pasture[N-1].rfind('H')
    if HP[0][0] != -1 :
      ph = False
    if  HP[1][0]!= -1:
      pv = False
    for m in range(N):
      if pasture[m][0] == "H":
        pv = False
        if (VP[0][0]== -1):
          VP[0][0] = m
        VP[0][1] = m
      if pasture[m][N-1] == "H":
        ph = False 
        if (VP[1][0] == -1):
          VP[1][0] = m
        VP[1][1] = m
    
    if ph:
      count += 1
    if pv:
      count += 1
    print(f"count1: {count} | HP:{HP}. VP:{VP}") 

  if K >= 2:
    print(f"K2: {K} -> count: {count}")
    col_start = HP[1][1] if HP[1][1] != -1 else 0
    col_end = HP[0][0] if HP[0][0] != -1 else N -1
    print(f"col_start: {col_start} col_end: {col_end}")
    for x in range(col_start + 1, col_end ):
      for y in range(1, N-1):
        print(f"pasture[{y}][{x}]={pasture[y][x]}")
        if pasture[y][x] == "H":
          break
      else:
        print("***")
        count += 1

    row_start = VP[1][1] if VP[1][1] != -1 else 0
    row_end = VP[0][0] if VP[0][0] != -1 else N -1
    print(f"row_start: {row_start} row_end: {row_end}")
    for x in range(row_start + 1, row_end):
      print(f"pasture[{x}]={pasture[x]}")
      if "H" in pasture[x]:
          continue
      else:
        print("&&&")
        count += 1

    print(f"count2: {count} | HP:{HP}  VP:{VP}") 

  if K >= 3:
    print(f"K3: {K}")
    col_start = HP[0][0] if HP[0][0] != -1 else N - 1
    print(f"col_start: {col_start}")
    for col in range(1, col_start):
      skip = False
      row_end = VP[1][1] if VP[1][1] != -1 and VP[1][1] != 0 else N - 1
      print(f"row_end: {row_end}")
      for y in range(1, row_end ):
        print(f"pasture[{y}][{col}]={pasture[y][col]}")
        if pasture[y][col] == 'H':
          skip = True
          break
      if skip:
        continue
      print(f"row_end: {row_end}, N-1: {N -1}")

      if (row_end == N-1):
        print(f"K31 ****")
        count += 1
      else:
        for y in range(row_end, N-1):
          print(f"y:[{y}] col{col}")
          if pasture[y][col] != 'H':
            if 'H' not in pasture[y][col:]:
              print(f"K32 ****")
              count += 1

    row_start = VP[0][0] if VP[0][0] != -1 else N - 1
    for row in range(1, row_start):
      skip = False
      col_start = HP[1][1] if HP[1][1] != -1 else N - 1 
      print(f"row:{row} col_start: {col_start}. {pasture[row][1:col_start]}")
      if 'H' in pasture[row][1:col_start]:
        print(f"skip H")
        continue
      
      if col_start == N - 1:
        print(f"K33 ****")
        count += 1
      else:
        for x in range(col_start, N-1):
          if pasture[row][x] != 'H':
            for t in range(row+1, N-1):
              if pasture[t][x] == 'H':
                break
            else:
              print(f"K34 ****")
              count += 1
    print(f"count3: {count}") 

  sys.stdout.write(f'{count}\n')
  
