"""
ID: nathand6
LANG: PYTHON3
TASK: cowtour
"""

#
# https://www.youtube.com/watch?v=ZU5iVPRqcZI&ab_channel=CodingwithDong
# https://jvonk.github.io/usaco/2018/11/01/cowtour.html
# need understand Floyd-Warshall on the matrix of distances
# 
import math

root_path="./training_2.4_3_cowtour/"
# When you run locally in replit, comment out the following line.
root_path = ""
N_MAX = 150
locX = [0] * N_MAX
locY = [0] * N_MAX
maxdist = [-1] * N_MAX
inf = 1e9

def dist(i,j):
  dx = locX[i]-locX[j]
  dy = locY[i]-locY[j]
  return math.sqrt( dx * dx + dy * dy )


fin = open(f"{root_path}cowtour.in", "r")
N = int(fin.readline().rstrip())
matrix = [ [0] * N for _ in range(N)]

for i in range(N):
  row = [int(p) for p in fin.readline().rstrip().split()]
  locX[i] = row[0]
  locY[i] = row[1]

for i in range(N):
  row = fin.readline().rstrip()
  for j in range(i):
    if (i==j):
      matrix[i][j] = 0
      continue
    if row[j] == '1':
      matrix[i][j] = dist(i, j)
      matrix[j][i] = matrix[i][j]
    else:
      matrix[i][j] = inf
      matrix[j][i] = inf

# non recursive way to calculate Floyd-Warshall shortest distance of two vertexs in a graph.
for k in range(N):
  for i in range(N):
    for j in range(N):
      matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j])


ans = inf 
for i in range(N):
  maxdist[i] = -1
  # generate longest distance for each vertex to any of the vertex in this graph. 
  for j in range(N):
    if matrix[i][j] == inf:
      continue 
    maxdist[i] = max(maxdist[i], matrix[i][j])

  # find the diameter of the graph. It should be the smallest one in the maxdist.
  # over here, we only calculate the diameter for newly generated graph that joins two sub-graph which were not connected.
  for j in range(i):
    # skip the vertex in same graph. We already have the diameter.
    if matrix[i][j] != inf:
      continue 
    
    # this is the formula to calcualte the new diameter of the new graph from two joined sub graph.
    ans = min(ans, maxdist[i] + dist(i,j) + maxdist[j])

# diameter of the the newly genearated graph should not be larger than the existing graph.
for i in range(N):
  ans = max(ans, maxdist[i])
#print(maxdist)

fin.close()
fout = open(f"{root_path}cowtour.out", "w")
ansString = "{:.6f}".format(ans)
fout.write(f"{ansString}\n")
fout.close()