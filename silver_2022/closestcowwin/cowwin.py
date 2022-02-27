"""
ID: bobsprite
LANG: PYTHON3
TASK: cowwin
"""

import sys
import bisect
import collections

count = 0
K = -1
M = -1
N = -1
patches = {}
rev_patches = {}
nhoj = []

(K , M,  N) = [int(n) for n in sys.stdin.readline().rstrip().split()]
for i in range(K):
  pat = sys.stdin.readline().rstrip().split()
  loc = int(pat[0])
  tasty = int(pat[1])
  patches[loc] = tasty
for i in range(M):
  nhoj.append(int(sys.stdin.readline().rstrip()))

nhoj.sort()

# print(f"nhoj: {nhoj}")
sorted_patches =  sorted (patches.keys())
# print(f"sorted_patches: {sorted_patches}")
grass_sections = []
i = 0
j = 0
start_cow = -1
end_cow = -1
current_section = []
while i < len(nhoj):
  end_cow = nhoj[i]
  while j < len(sorted_patches):
    patch = sorted_patches[j]
    if(patch < end_cow and patch > start_cow):
      # print(f"patch {patch} in range: {start_cow}, {end_cow}")
      current_section.append((patch, patches[patch] ))
    else:
      if (current_section):
        grass_sections.append((start_cow, end_cow, current_section))
      current_section = []
      start_cow = end_cow
      break
    j += 1
  if j == len(sorted_patches):
    #iterated all sorted patches.
    break;
  i += 1
# print(f"j: {j}, len(sorted_patches): {len(sorted_patches)}")
if j < len(sorted_patches):
  current_section = []
  i = 0
  for i in range(j, len(sorted_patches)):
    patch = sorted_patches[i]
    current_section.append((patch, patches[patch] ))
  grass_sections.append((end_cow, -1 , current_section))
# print(f"grass_sections: {grass_sections}")

cal_sec = []
for i in range(len(grass_sections)):
  (start_cow, end_cow, section) = grass_sections[i]
  total_tasty = 0
  highest_single_tasty = 0

  if (start_cow == -1 or end_cow == -1):
    for j in range(len(section)):
      (loc, tasty) = section[j]
      total_tasty += tasty
      highest_single_tasty = total_tasty
  else:
    influence = {}
    for j in range(len(section)):
      (loc, tasty) = section[j]
      total_tasty += tasty
      if (end_cow - loc) > (loc - start_cow):
        left = start_cow
        right = loc + (loc - start_cow)
      else:
        left = loc - (end_cow - loc)
        right = end_cow
      # print(f"influence[left]: {influence[left] if left in influence else 0 } tasty: {tasty}")
      prv_left = influence[left] if left in influence else 0
      influence[left]=tasty + prv_left
      pre_right = influence[right] if right in influence else 0
      influence[right]= -1*tasty + pre_right
    single_tasty = 0
    # print(f"influence: {influence}")
    for k in sorted(influence.keys()):
      single_tasty += influence[k]
      # print(f"single_tasty: {single_tasty}. highest_single_tasty: {highest_single_tasty}")
      if single_tasty > highest_single_tasty:
        highest_single_tasty = single_tasty
    
  cal_sec.append( highest_single_tasty)
  cal_sec.append( total_tasty - highest_single_tasty)
  # print(f"cal_sec: {cal_sec}")
sorted_sec = sorted(cal_sec, reverse=True)

final_tasty = 0
for i in range(N):
  final_tasty += sorted_sec[i]

sys.stdout.write(f"{final_tasty}")