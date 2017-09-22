t=int(input())
for i in range(0, t):
    n,k=input("").split()
    n=int(n)
    k=int(k)
    A=[int(n) for n in input().split()]
    start=0
    ans=0
    count=0
    for j in range(0, n):
        parans=0
        for m in range(j, n):
            parans=parans^A[m]
            if(parans<k):
                count=count+1
    print(count)
