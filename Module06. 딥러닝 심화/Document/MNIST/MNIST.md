# 손글씨 DB(MNIST)

### 1. MNIST 데이터 정보

- MNIST
  - 1980년대 미국 국립표준기술연구소(NIST, National Institute of Standards and Technology) 에서 수집
  - 0~9까지 흑백 손글씨 데이터
  - 28 × 28 사이즈 (높이, 너비)
  - Train set(60,000), test set(10,000)

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210528162131394.png">

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210528162141157.png">

<br>

- 입력: 흑백 이미지

- 출력: 0-9의 숫자 중 하나

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210528162214239.png">

  

---

### 2. 모델링

#### 1) MNIST DNN

- 입력 이미지 불러오기

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210528162515132.png">

  

- One-Hot-Encoding

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210528162526295.png">

  

- 모델 설계 및 컴파일

  - 연쇄형

    <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210528162604512.png">

    

  - 함수형

    <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210528162614831.png">

    

    ```python
    input_tensor = Input(shape=(784,), name='input_tensor')  
    hidden_1 = Dense(units=256, activation='sigmoid', name='hidden_1')(input_tensor)
    hidden_2 = Dense(units=256, activation='sigmoid', name='hidden_2')(hidden_1)
    hidden_3 = Dense(units=256, activation='sigmoid', name='hidden_3')(hidden_2)
    hidden_4 = Dense(units=256, activation='sigmoid', name='hidden_4')(hidden_3)
    output_tensor = Dense(num_classes, activation='softmax', name='output_tensor')(hidden_4)
    model = Model(inputs=input_tensor, outputs=output_tensor)
    model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy']) 
    ```

  - Model summary

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210528163045339.png">



<br>

- 학습

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210528163115246.png">

  

  - Batch_size : size만큼 메모리에 올려서 학습
  - Epochs : 학습 데이터 전체를 한 바퀴 도는 것

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210528163150389.png">



<br>

- 모델 성능 평가

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210528163218721.png">

  

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210528163221813.png">



- 학습 모델 그래프

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210528163427324.png">

  

---

#### 2) MNIST CNN

- 모델 설계

  ```python
  input_tensor = Input(shape=input_shape)
  
  x = Conv2D(32, kernel_size=(3, 3), padding='valid', name='Conv1')(input_tensor)
  x = Activation('relu', name='relu_1')(x)
  x = Conv2D(32, kernel_size=(3, 3), padding='valid', name='Conv2')(x)
  x = Activation('relu', name='relu_2')(x)
  x = MaxPooling2D(pool_size=(2, 2), name='pool_1')(x)
  x = Flatten()(x)  
  x = Dense(units=128, name='hidden_1')(x)
  x = Activation('relu', name='relu_3')(x)
  x = Dense(units=10, name='hidden_2')(x)   # 0-9로 10개의 값을 출력할 것임을 명시해줌
  output_tensor = Activation('softmax', name='output_tensor')(x)
  
  model = Model(inputs=input_tensor, outputs=output_tensor)
  model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy'])
  ```

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210528163535175.png">

  

- 모델 설계 및 컴파일

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210528163622464.png">

  

- 학습

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530135823554.png">

  

- 학습 모델 그래프

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530135926996.png">

  <br>

