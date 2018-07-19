# C
A, B, C, D, E, F = map(int, input().split())

A_limit = F // (100*A)

max_density = 0.0
max_suger = 0
max_total = 0

for a in range(A_limit + 1):
    B_limit = (F-100*A*a) // (100*B)
    for b in range(B_limit + 1):
        water = 100*A*a + 100*B*b
        
        suger_limit = min(water*E // 100, F - water)
        
        suger_ = 0
        for c in range(suger_limit // C + 1):
            d = (suger_limit - C*c) // D
            suger = C*c + D*d
            suger_ = max(suger, suger_)
        
        if (suger_ + water) > 0:
            if suger_ / (suger_ + water) >= max_density:
                max_density = suger_ / (suger_ + water)
                max_suger = suger_
                max_total = suger_ + water

print(str(max_total)+" "+str(max_suger))

