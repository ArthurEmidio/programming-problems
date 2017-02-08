#!/usr/bin/python3

# BEGIN template
import sys
import re
import pprint

def dbg(x,y=''):
  if len(y) > 0: y += ' = '
  sys.stderr.write('\n>>> '+y+pprint.pformat(x)+'\n')

oo = 0x3f3f3f3f3f3f3f3f
# END template

def main():
  for t in range(int(input())):
    # input
    n = int(input())
    users = set(input().split())
    m = int(input())
    msg = []
    for i in range(m):
      user, text = input().split(':')
      alts = set()
      if user != '?':
        alts.add(user)
      else:
        # this shit is pretty fucked up, dude
        alts = users - set(re.findall('[a-zA-Z][a-zA-Z0-9]*',text))
      msg.append(dict(user=user, text=text, users=alts))
    # remove before and after
    for i in range(m):
      if len(msg[i]['users']) > 1: continue
      t = False
      if 0 <= i-1:  
        msg[i-1]['users'].difference_update(msg[i]['users'])
        t = True
      if T and i+1 <  m:  msg[i+1]['users'].difference_update(msg[i]['users'])
    # compute answer
    last = ''
    impo = False
    for i in range(m):
      msg[i]['users'].discard(last)
      if len(msg[i]['users']) == 0:
        impo = True
        break
      last = next(iter(msg[i]['users']))
      msg[i]['user'] = last
    if impo:
      print('Impossible')
      continue
    for i in range(m):
      print(msg[i]['user']+':'+msg[i]['text'])
    '''
    dp = [[0 for j in range(n+5)] for i in range(m+5)]
    for i in range(1,n+5):
      dp[m+1][i] = oo
    for i in range(m,0,-1):
      for j in range(n+1):
        for k in msg[i]['users']:
          if k != j and dp[i+1][k]:
            dp[i][j] = k
            break
    # output
    if not dp[1][0]:
      print('Impossible')
      continue
    j = 0
    for i in range(1,m+1):
      print(users[dp[i][j]]+':'+msg[i]['text'])
      j = dp[i][j]'''

main()