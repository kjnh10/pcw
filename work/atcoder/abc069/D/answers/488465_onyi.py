# encoding:utf-8
 
def main():
	h, w = list(map(int, input().split()))
	n = int(input())
	nums = list(map(int, input().split()))
	calc(h, w, n, nums)

def calc(h, w, n, nums):
	out_raw = []
	for i, num in enumerate(nums):
		out_raw.extend([str(i + 1) for _ in range(num)])

	for i in range(h):
		tmp = out_raw[i * w:(i + 1) * w]
		if i % 2 == 0:
			print(" ".join(tmp))
		else:
			print(" ".join(tmp[::-1]))

if __name__ == '__main__':
	main()
