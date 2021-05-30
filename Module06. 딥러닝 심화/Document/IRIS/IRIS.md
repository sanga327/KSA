# IRIS

### 1. 데이터 정보

- 데이터명: IRIS

- record: 150

- field: 5

- data: 아이리스(붓꽃) 데이터에 대한 데이터이다. 꽃잎의 각 부분의 너비와 길이등을 측정한 데이터이며 150개의 레코드로 구성되어 있다.

  | 컬럼명       | 의미                                                        | 데이터 타입 |
  | ------------ | ----------------------------------------------------------- | ----------- |
  | Species      | 붓꽃의 종. setosa, versicolor, virginica 세 가지 값 중 하나 | Factor      |
  | Sepal.Width  | 꽃받침의 너비                                               | Number      |
  | Sepal.Length | 꽃받침의 길이                                               | Number      |
  | Petal.Width  | 꽃잎의 너비                                                 | Number      |
  | Petal.Length | 꽃잎의 길이                                                 | Number      |

<br>

---

### 2. 모델링

#### 1) DNN Model

```python
model = Sequential()
model.add(Dense(64, input_shape=(4,), activation='relu'))
model.add(Dense(64, activation='relu'))
model.add(Dense(3, activation='softmax'))

model.compile(loss='categorical_crossentropy', optimizer='Adam', metrics=['accuracy']) 
```

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530164846083.png">

<br>

- 모델 성능 평가

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/iris_dnn_test.png">

<br>

- 학습 모델 그래프

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/iris_dnn_acc.png">

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/iris_dnn_loss.png">