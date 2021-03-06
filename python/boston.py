from sklearn.datasets import load_boston
from sklearn.datasets import load_iris
from sklearn.datasets import load_digits
'''
boston = load_boston()
print(boston.data.shape)
'''

data,target = load_boston(return_X_y=True)
print(data.shape)
print(target.shape)
iris = load_iris()
print(iris.data.shape)
print(iris.target.shape)
list(iris.target_names)

digits=load_digits()
print(digits.data.shape)
print(digits.images.shape)

import matplotlib.pyplot as plt
plt.matshow(digits.images[9])
plt.show()