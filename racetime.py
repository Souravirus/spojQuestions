n, q = input().split()
n = int(n)
q = int(q)
a=[]
for _ in range(n):
    m=int(input())
    a.append(m)
for _ in range(q):
    A=[n for n in input().split()]
    if(A[0]=='C'):
        A[1]=int(A[1])
        A[2]=int(A[2])
        A[3]=int(A[3])
        count=0
        for j in range(A[1]-1, A[2]):
            if(a[j]<=A[3]):
                count=count+1
        print(count)
    else:
        A[1]=int(A[1])
        A[2]=int(A[2])
        a[A[1]-1]=A[2]
