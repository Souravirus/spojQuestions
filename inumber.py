T=input()
T=int(T)
for _ in range(T):
    n=input()
    n=int(n)
    count=0
    arr=''
    for i in range(n):
        if count<n and (n-count)>9:
            arr=arr+'9'
            count=count+9
        else: 
            arr=arr+str(n-count)
            break;
    if(int(arr[::-1])%n!=0):
        count=0
        while(1):
            count=count+1
            carry=[]
            carry.append(0)
            arr=list(arr)
            if arr[0]=='0':
                arr[0]='9'
                carry.append(0)
            else:
                arr[0]=str(int(arr[0])-1)
                carry.append(1)
            for i in range(1,len(arr)):
                flag=0
                if carry[i]==0:
                    break
                elif carry[i]==1:
                    if arr[i]=='9':
                        #print("arr[i] in f", arr[i])
                        arr[i]='0'
                        carry.append(1)
                        flag=1
                    else:
                        #print("arr[i] in else", arr[i])
                        arr[i]=str(int(arr[i])+1)
                        carry.append(0)
            sum=0
            for i in range(0, len(arr)):
               sum=sum+int(arr[i]) 
               if flag==1:
                   sum=sum+1
            arr="".join(arr)
            if flag==1:
                arr=arr+'1'
            #print("last number", int(arr[::-1]))
            if sum==n:
                if int(arr[::-1])%n==0:
                    break
    arr=arr[::-1]
    print("count ", count)
    print(int(arr))
