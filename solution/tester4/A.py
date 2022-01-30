# O(n)
import re

s = input()
res = ''

while s:
  ar = re.findall(r'^(?:(\d+)([a-z]))', s)
  assert len(ar) <= 1

  if not ar:
    res += s[0]
    s = s[1:]
  else:
    t, c = ar[0]
    needle = t + c
    res += c * int(t)
    s = s[len(needle):]

print(res)
