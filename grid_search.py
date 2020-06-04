def grid_search(G,P):
    lenp=len(P)
    leng=len(G)
    res=False
    for i in range(leng-lenp+1):
        
        if P[0] in G[i]:
            if lenp==1 : return True
            res=grid_search(G[1:],P[1:])

def main():        
    rG=int(input("#rows in g"))
    g=[]
    print("enter g")
    for i in range(rG):
        s=input()
        g.append(s)

    rP=int(input("#rows in p"))
    p=[]
    print("enter p")
    for i in range(rP):
        s=input()
        p.append(s)
    print(grid_search(g,p))

main()


