K=int(input())

def p_win(Rate_winner,Rate_loser):
    bunbo=1+10**((Rate_loser-Rate_winner)/400)
    return 1/bunbo

Elo=[]
for Nin in range(0,2**K,1):
    Elo.append(int(input()))


Mazai=[]
for idx in range(0,K+1,1):
    Mazai.append([None]*(2**K))

for idx in range(0,2**K,1):
    Mazai[0][idx]=1 #0回勝利 参加できていれば


for idx in range(1,K+1,1):
    for man_no in range(0,2**K,1):
        look_bit=man_no//(2**(idx-1))%2
        inv_bit= 0 if look_bit==1 else 1
        
        possible_oppoments_st=((man_no//(2**(idx)))*2+inv_bit)*(2**(idx-1))
        # bitwise
        # 1 2 3 .. idx idx+1 idx+2 ...
        # * * * .. inv same  same  ...

        tmp=0
        for opp_off in range(0,2**(idx-1),1):
            tmp+=Mazai[idx-1][possible_oppoments_st+opp_off]*p_win(Elo[man_no],Elo[possible_oppoments_st+opp_off])

        Mazai[idx][man_no]=Mazai[idx-1][man_no]*tmp

for man_no in range(0,2**K,1):
    print(Mazai[K][man_no])
    
