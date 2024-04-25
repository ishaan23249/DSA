import torch
import numpy as np
# x = torch.empty(2, 3)
# y = torch.rand(2, 3)
# z = torch.zeros(2, 3)
# a = torch.ones(2, 3, dtype = torch.float16)
# b = torch.tensor([2, 5,6])
# print(x)
# print(y)
# print(z)
# print(a.dtype)
# print(b)

# a = torch.ones(2, 2)
# b = torch.zeros(2, 2)
# print(a)
# print(b)
# c = a+b
# print(c)
# b.add_(a)
# print(b)
# z = a-b
# print(z)
# k = torch.mul(a, b) 

# Resizing the Tensor. 
# x = torch.rand(4, 4)
# print(x)

# y = x.view(2, 8)
# print(y)

a = torch.ones(4)
print(a)
# Converting to numpy array. 
b = a.numpy()
print(type(b))

a.add_(1)
print(a)
print(b)

# Converting to tensor 
a = np.ones(5)
print(a)
b = torch.from_numpy(a)
print(b)

a+=1
print(a)
print(b)

