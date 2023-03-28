# -*- coding: utf-8 -*-
"""SVM.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/13EqyU_eLJ5bA87s7dM9MS92lZpDvHab9
"""

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv('Social_Network_Ads.csv')

data.head()

X = data.iloc[:, [2, 3]].values
y = data.iloc[:, 4].values

from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.25,random_state=0)

from sklearn.preprocessing import StandardScaler

sc = StandardScaler()

X_train = sc.fit_transform(X_train)
x_test = sc.transform(X_test)

from sklearn.svm import SVC
classifier = SVC()
classifier.fit(X_train, y_train)

y_pred = classifier.predict(x_test)

from sklearn.metrics import confusion_matrix, accuracy_score
cm = confusion_matrix(y_test, y_pred)
print(cm)
accuracy_score(y_test,y_pred)

from sklearn.tree import DecisionTreeClassifier
dis_classifier = DecisionTreeClassifier(criterion='entropy', random_state=0)
dis_classifier.fit(X_train, y_train)

y_pred_dis = dis_classifier.predict(x_test)

cml = confusion_matrix(y_test, y_pred_dis)
print(cml)

accuracy_score(y_test, y_pred_dis)