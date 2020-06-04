books={}
checkouts={}
borrowers={}
while True:
    var=input().strip()
    if var=="Books":
        continue
    if var=="Borrowers":
        break
    s1,s2=var.split('~')
    books[s1]=s2

#print(books)

while True:
    var=input().strip()
    if var=='Checkouts':
        break
    s1,s2=var.split('~')
    borrowers[s1]=s2

output=[]
while True:
    var=input().strip()
    if var=='EndOfInput':
        break
    s1,s2,s3=var.split('~')
    checkouts[s1]=[s2,s3]
    output.append(checkouts[s1][1]+'~'+borrowers[s1]+'~'+checkouts[s1][0]+'~'+books[checkouts[s1][0]])


# output=[]
# for keys in checkouts:
#     output.append(checkouts[keys][1]+'~'+borrowers[keys]+'~'+checkouts[keys][0]+'~'+books[checkouts[keys][0]])

output.sort()
for ele in output:
    print(ele)

