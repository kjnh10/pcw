import math
A,B,C,D,E,F = map(int, input().split())
result_noudo=None
result_satosui=None
result_sato=None

for a in range(math.floor(F/100*A)+1):
    for b in range(math.floor((F-100*A*a)/100*B)+1):
        for c in range(math.floor((F-100*A*a-100*B*b)/C)+1):
            for d in range(math.floor((F-100*a*A-100*b*B-C*c)/D)+1):
                sum_under=100*a*A+100*b*B+C*c+D*d
                if (a==0 and b==0) or (d==0 and c==0):
                    continue
                sum_top=C*c+D*d
                noudo=(100*sum_top)/sum_under
                if sum_under<=F and noudo<=(100*E)/(100+E) and (result_noudo==None or noudo>result_noudo):
                    result_noudo=noudo
                    result_satosui=sum_under
                    result_sato=sum_top
if result_noudo==None:
    result_satosui=100*A
    result_sato=0
print(str(result_satosui)+" "+str(result_sato))