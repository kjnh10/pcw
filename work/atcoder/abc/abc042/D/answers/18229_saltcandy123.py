M=10**9+7;F=lambda X:pow(X,M-2,M);H,W,A,B=map(int,input().split());Z=C=1
for I in range(H-1):Z=C=C*(W+H-B-2-I)*F(I+1)%M
for I in range(1,H-A):C=C*(B-1+I)*(H-I)%M*F(I*(W+H-B-1-I))%M;Z=(Z+C)%M
print(Z)