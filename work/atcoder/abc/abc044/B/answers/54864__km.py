import collections
print('Yes' if len([1 for x in collections.Counter(input()).values() if x % 2]) == 0 else 'No')
