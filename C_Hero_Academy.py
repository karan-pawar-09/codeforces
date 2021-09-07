t=int(input())
while t!=0 :
    t=t-1
    n=int(input())
    arr = list(map(int, input().split()))
    sum=0
    for i in arr:
        sum+=i

    avg = sum/n
    ans=int(0)
    for i in arr:
        ans+=abs(avg-i)
    print(int(ans))

    
    

    