no = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}


def romantointegerconverter(inp):
  out = 0
  i = 0
  leng = len(inp)
  while i < len(inp):
    val1 = no[inp[i]]
    if i + 1 < leng:
      val2 = no[inp[i + 1]]
      if val1 >= val2:
        out += val1
        i += 1
      else:
        out += (val2 - val1)
        i += 2
    else:
      out += val1
      i += 1
  return out
  
def romantointegerconverter2(inp):
  out=0
  leng=len(inp)
  for i in range(leng-1):
    if no[inp[i]]<no[inp[i+1]]:
      out-=no[inp[i]]
    else:
      out+=no[inp[i]]
  else:
    out+=no[inp[-1]] #last number is always added
  return out
    
            
inp = 'IV'    
print(romantointegerconverter(inp))
print(romantointegerconverter2(inp))
