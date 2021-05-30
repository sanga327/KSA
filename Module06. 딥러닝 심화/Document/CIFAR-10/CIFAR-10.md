# CIFAR-10

### 1. 데이터 정보

- Airplane, automobile, bird, cat, deer, dog, frog, horse, shop, truck 총 10개 
- 32 × 32 사이즈 (높이, 너비), 3채널
- Train set(50,000), test set(10,000)

<br>

---

### 2. 모델링

#### 1) CNN

- 모델 설계

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530144055399.png">

  

```python
input_layer = Input(shape=input_shape)
x = Conv2D(32, kernel_size=(3, 3), padding='same', strides=1, name='Conv1')(input_layer)
x = LeakyReLU()(x)
x = Conv2D(32, kernel_size=(3, 3), padding='same', strides=2, name='Conv2')(x)
x = LeakyReLU()(x)
x = Conv2D(64, kernel_size=(3, 3), padding='same', strides=1, name='Conv3')(x)
x = LeakyReLU()(x)
x = Conv2D(64, kernel_size=(3, 3), padding='same', strides=2, name='Conv4')(x)
x = LeakyReLU()(x)
x = Flatten()(x)
x = Dense(128)(x)
x = LeakyReLU()(x)
x = Dense(NUM_CLASSES)(x)
output_layer = Activation('softmax')(x)
model = Model(input_layer, output_layer)
```

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530143839482.png">



- 학습 모델 그래프

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530144123107.png">

  

- 학습 결과

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530144143638.png">

  

<br>

---

#### 2) DNN

```python
input_layer = Input(shape=(32, 32, 3))
x = Flatten()(input_layer)
x = Dense(units=200, activation='relu')(x)
x = Dense(units=200, activation='relu')(x)
output_layer = Dense(units=10, activation='softmax')(x)
model = Model(inputs=input_layer, outputs=output_layer)
```

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530143935965.png">



- 학습 모델 그래프

  ​	<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530143955598.png">

  

- 학습 결과

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530144031281.png">