s = input('문자열을 입력하세요 : ')
num = 0
i = 0
cha = s[i]

while i<len(s) :
    if s[i] == cha :
        num += 1
        i += 1
    else :
        print(s[i-1],end='')
        print(num, end='')
        num=1
        cha = s[i]
        i+=1

print(s[i-1],end='')
print(num, end = '')
