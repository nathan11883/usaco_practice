"""
ID: nathand6
LANG: PYTHON3
TASK: hps
"""
root_path="./silver_2017/hps/"
# When you run locally in replit, comment out the following line.
root_path = ""
games = []
#print(f"{root_path}hps.in")
with open( f"{root_path}hps.in") as fr:
    games = [line.rstrip() for line in fr]
game_num = int(games.pop(0))

hoof = [0] * game_num
paper = [0] * game_num
scissors = [0] * game_num

max_win = 0

def get_max(g1, g2, i, existing_max):
  new_sum = g1[i] + g2[game_num-1] - g2[i]
  return max(new_sum, existing_max)
  

hoof_win = 0
scissors_win = 0
paper_win = 0

#pre-sum add them up
for i in range(game_num):
  scissors[i] =  0 if i == 0 else scissors[i-1]
  paper[i] = 0 if i == 0 else paper[i-1]
  hoof[i] = 0 if i == 0 else hoof[i-1]
  if (games[i] == "P"):
    scissors_win += 1
    scissors[i] = scissors_win
  elif (games[i] == "H"):
    paper_win += 1
    paper[i] = paper_win
  else:
    hoof_win += 1
    hoof[i] = hoof_win
#print(hoof)
##print(paper)
#print(scissors)
for i in range(game_num):
  max_win = get_max(hoof, paper, i, max_win)
  max_win = get_max(paper,hoof , i, max_win)
  max_win = get_max(hoof, scissors, i, max_win)
  max_win = get_max(scissors, hoof, i, max_win)
  max_win = get_max(scissors, paper, i, max_win)
  max_win = get_max(paper, scissors, i, max_win)

x = open(f"{root_path}hps.out", "w")
x.write(f"{max_win}\n")
x.close()

"""
Passed.
""" 
