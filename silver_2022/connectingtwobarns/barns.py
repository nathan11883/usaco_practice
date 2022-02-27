"""
ID: bobsprite
LANG: PYTHON3
TASK: barns
"""

import sys

def dfsearch(node,visit,i, bag):
    stack = [i]

    while stack:
        vertex = stack.pop()
        if visit[vertex] or vertex in bag:
            continue
        bag.add(vertex)
        visit[vertex] = True
        if node[vertex] == -1:
          continue
        for neighbor in node[vertex]:
            stack.append(neighbor)

    return

# def dfsearch(node, visit, i, bag):
#   # print(f"dfs i: {i}, node {node}.  visit {visit} ")
#   if (visit[i]):
#     # print(f"visited [{i}]={visit[i]}")
#     return
#   visit[i] = True
#   bag.add(i)
#   if (node[i] == -1):
#     # print(f"-1 node [{i}]={node[i]}")
#     return 
#   # print(f"node i {i}: {node[i]}")
#   for x in node[i]:
#     dfsearch(node, visit, x, bag )
    
def generate_sub_graph(numNode, m, t):
  TF = None
  TL = None

  Node = [-1] * (numNode+1)
  NodeVisited = [False] * (numNode+1)
  for i in range(len(t)):
    (ai,aj)=t[i]
    if (Node[ai] == -1 ):
      Node[ai] = [aj]
    else:
      Node[ai].append(aj)
    
    if (Node[aj] == -1):
      Node[aj] = [ai]
    else:
      Node[aj].append(ai)
  # print(f"Node: {Node}")
  # print(f"NodeVisited: {NodeVisited}")
  subgrap = []
  for i in range(1, len(Node)):
    if (not NodeVisited[i]):
      bag = set()
      dfsearch(Node, NodeVisited, i, bag)
      # print(f"bag: {bag}")
      oneInBag = 1 in bag
      lastField = numNode in bag
      if oneInBag or lastField:
        if oneInBag:
          TF = bag
        if lastField:
          TL = bag
      else:
        subgrap.append(bag)
  
  sortedgraph = []
  for i in range(len(subgrap)):
    sortedgraph.append(sorted(subgrap[i]))

  
  TF = sorted(TF)
  TL = sorted(TL)
  return TF, TL, sortedgraph

def find_shortest_distance(g1, g2):
  p1 = 0
  p2 = 0
  shortest = float('inf')
  while (p1 < len(g1) and p2 < len(g2)):
    # print(f"{p1} {g1} . {p2} {g2}")
    if (g1[p1] > g2[p2]):
      dis = g1[p1] - g2[p2]
      p2 += 1;
    elif (g1[p1] < g2[p2]):
      dis =  g2[p2] - g1[p1]
      p1 += 1
    else:
      dis = 0
      shortest = dis
      break
    if dis < shortest:
      shortest = dis 
  # print(f"shortest: {shortest}.| {g1} | {g2}")
  return shortest


def get_cost(TF, TL, g, smallest_cost):
  # print(f"get_cost: {TF} {TL} {g}")
  short1 = find_shortest_distance(TF, g)
  cost1 = short1 * short1 
  # print(f"cost1 {cost1}")
  if cost1 >= smallest_cost:
    return smallest_cost

  short2 = find_shortest_distance(TL, g)
  cost2 = short2 * short2 
  # print(f"cost2 {cost2}")
  if cost2 >= smallest_cost:
    return smallest_cost

  if cost1 + cost2 >= smallest_cost:
    return smallest_cost
  else:
    # print(f"cost1 + cost2 {cost1 + cost2}")
    return cost1 + cost2

def process_case(n,m,t):
  # print(f"{n} {m} {t}")
  TF, TL, TM = generate_sub_graph(n, m, t)
  # print(TF, TL, TM)

  shortest_direct = find_shortest_distance(TF, TL)
  final = shortest_direct * shortest_direct

  if TM:
    for g in TM:
      if g:
        final = get_cost(TF, TL, g, final) 
      # print(f"{g} : {final}")
  sys.stdout.write(f'{final}\n')
  return  

count = 0
T = -1
tindex = []
tcase = []

T = int(sys.stdin.readline().rstrip())
for tc in range(T):
  (N,M) = [int(n) for n in sys.stdin.readline().rstrip().split()]
  tc = []
  tindex.append([N, M])
  for m in range(M):
    pth = [int(n) for n in sys.stdin.readline().rstrip().split()]
    tc.append(pth)
  tcase.append(tc)
  
# print(T)
# print(tindex)
# print(tcase)


for i in range(len(tindex)):
  (n,m) = tindex[i]
  t = tcase[i]
  # print(n, m)
  # print(t)
  process_case(n,m,t)
