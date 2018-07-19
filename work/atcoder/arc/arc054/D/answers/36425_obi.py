# def makelist(n, m):
# 	return [[0 for i in range(m)] for j in range(n)]
P = float(input())

def moore(x):
	return pow(2, x / 1.5)
def check(x):
	tmp = x + P / moore(x)
	return tmp

# 下に凸のグラフの最小値
def ternarySearch(small, big):
	END = 5e-9
	VOL = 1e-9  # END // 2 より小さく
	def func(small, big):
		midl = (big + small) / 2
		midr = midl + VOL
		if big - small < END:  # 終了条件
			return big
		else:
			if check(midl) >= check(midr):
				return func(midl, big)
			else:
				return func(small, midr)

	return func(small, big)



##
ans = ternarySearch(0, 1000)
print(ans + P / moore(ans))
