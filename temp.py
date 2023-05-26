# counting frequency of tokens in Hindi(Target) language 
f = open("Joshua-IPC.en-hi.hi", "r",encoding="utf8")
arr=[]
for x in f:
    arr.append(x) 
countoftokens = {} 
num = 0 ;
for x in arr:
    tokens="" 
    for ch in x:
        if ch not in ['"','।',"?",":","'","-","\n","(",")",".","[","]","/","‘","’","·",",","\0","”","“"]: tokens = tokens+ch
        else:
            tokens = tokens+' '
    tokens = tokens.split(' ') 
    for token in tokens:
        if(token in countofto*kens): countoftokens.update({token:countoftokens[token]+1})
        else:
            countoftokens[token] = 1
sortedcountoftokens = sorted(countoftokens.items(), key=lambda x:x[1])
pairsize = len(sortedcountoftokens)
for i in range(0,pairsize):
    print(sortedcountoftokens[pairsize-i-1][0],sortedcountoftokens[pairsize-i-1][1])
f.close()

# counting frequency of tokens in English (source) language f = open("Joshua-IPC.en-hi.en", "r",encoding="utf8")
arr=[]
tokenizer = RegexpTokenizer(r'\w+')
for x in f:
    x = x.lower(); 
    arr.append(x)
countoftokens = {}
num = 0 ; 
for x in arr:
    tokens = tokenizer.tokenize(x) 
    for token in tokens:
        if(token in countoftokens): countoftokens.update({token:countoftokens[token]+1})
        else:
            countoftokens[token] = 1
sortedcountoftokens = sorted(countoftokens.items(), key=lambda x:x[1])
pairsize = len(sortedcountoftokens)
for i in range(0,pairsize):
    print(sortedcountoftokens[pairsize-i-1][0],sortedcountoftokens[pairsize-i-1][1])
f.close()