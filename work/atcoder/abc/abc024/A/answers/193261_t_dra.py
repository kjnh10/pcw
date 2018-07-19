a, b, c, k = map(int, input().split())
s, t = map(int, input().split())

children = a * s
adult = b * t
service = (s + t) * c if (s + t) >= k else 0

people = children + adult - service
print(people)
