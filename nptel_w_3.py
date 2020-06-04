def orangecap(d):
    player_totals={}
    for key in d:
        for key1 in d[key]:
            try:
                player_totals[key1]+=d[key][key1]
            except:
                player_totals[key1]=d[key][key1]
    highest=0
    player=""
    for key in player_totals:
        if highest<player_totals[key]:
            highest=player_totals[key]
            player=key
    return (player,highest)

# mydict={'test1':{'ashwin':84,'kohli':120},'test2':{'ashwin':59,'pujara':42}}
# print(orangecap(mydict))

def addpoly(p1,p2):
    p3=[]
    i=0
    j=0
    lenp1=len(p1)
    lenp2=len(p2)

    while i<lenp1 and j<lenp2:
        if p1[i][1]>p2[j][1]:
            t3=p1[i]
            i+=1
        elif p2[j][1]>p1[i][1]:
            t3=p2[i]
            j+=1
        else:
            if p1[i][0]+p2[j][0]==0:
                j+=1
                i+=1
                continue
            t3=(p1[i][0]+p2[j][0],p1[i][1])
            j+=1
            i+=1
        p3.append(t3)
    
    if j==lenp2 and i<lenp1:
        for ele in p1[i:]:
            p3.append(ele)
    elif i==lenp1 and j<lenp2:
        for ele in p2[j:]:
            p3.append(ele)
    
    return p3

# result=addpoly([(2,1)],[(-2,1)])
# print(result)

def multpoly(p1,p2):
    #p3=[]
    res=[]
    for t1 in p1:
        for t2 in p2:
            t3=(t2[0]*t1[0] , t2[1]+t1[1])
            res=addpoly(res,[t3])
        
    return res

# p=multpoly([(1,1),(-1,0)],[(1,2),(1,1),(1,0)])
# print(p)