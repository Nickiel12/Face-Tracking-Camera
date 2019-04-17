import struct

packed = struct.pack('>b', 0)
print(packed)
arr = []
print(arr)
arr.append(struct.pack('>b', 0))
print(arr)