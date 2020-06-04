s=input()
lens=len(s)
mydict={}
k=10**9+7
for i in range(0,lens):
    value=lens-i
    value=(i+1)*int('1'*value)
    try:
        mydict[s[i]]=(mydict[s[i]]%k+value%k)%k
    except:
        mydict[s[i]]=value%k
sum=0
for key in mydict:
    sum=(sum%k+(int(key)*mydict[key])%k)%k
#print(mydict)
print(sum%k)