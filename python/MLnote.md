# Machine Learning in Python

## Prerequisites
* numpy
* matplotlib
* scipy
* sklearn

## Basics of sklearn
1. Classification
2. Regression
3. Clustering
4. Dimension-lowering
5. Model selection
6. Data pre-processment

>Classification

|Model |Loaded Modules |
|:---: |:----------:|
|最近邻算法|neighbors.NearestNeighbors|
|支持向量机|svm.SVC|
|朴素贝叶斯|naive_bayes.GaussianNB|
|决策树|tree.DecisionTreeClassifier|
|集成方法|ensemble.BaggingClassifier|
|神经网络|neural_network.MLPClassifier|
**Other cases are not presented here.**

## 无监督学习
利用无标签的数据学习数据的分布或者数据与数据之间的关系。
* 与`有监督学习`最大的区别在于数据是否有标签
* 最常应用的场景是`聚类clustering``降维Dimension Reduction`
  * 聚类就是根据数据的“相似性”将数据聚为几类的过程。
  * 欧式距离（平面几何方法）是最常用的一种距离度量方法。
  * 另一种是曼哈顿距离，计算直角边距离。
  * 马氏距离：表示数据的协方差距离，s为协方差矩阵。$d(x_i,x_j)=\sqrt{(x_i-x_j)^Ts^{-1}(x_i-x_j)}$
  * 夹角余弦（将数据集引申为向量）
### sklearn.cluster
