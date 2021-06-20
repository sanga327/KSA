# [모듈 6] 딥러닝 심화

**[장소] KSA 한국표준협회**

**[강사] 장우혁 상명대 강사님**

---

## [실습]

### 1. [손글씨 DB (MNIST)](https://github.com/sanga327/KSA/tree/main/Module06.%20%EB%94%A5%EB%9F%AC%EB%8B%9D%20%EC%8B%AC%ED%99%94/Document/MNIST/MNIST.md)

- CNN | DNN

###  2. [IRIS](https://github.com/sanga327/KSA/tree/main/Module06.%20%EB%94%A5%EB%9F%AC%EB%8B%9D%20%EC%8B%AC%ED%99%94/Document/IRIS/IRIS.md)

- DNN

### 3. [CIFAR-10](https://github.com/sanga327/KSA/tree/main/Module06.%20%EB%94%A5%EB%9F%AC%EB%8B%9D%20%EC%8B%AC%ED%99%94/Document/CIFAR-10/CIFAR-10.md)

- CNN | DNN

### 4. [Dog & Cat Classification](https://github.com/sanga327/KSA/tree/main/Module06.%20%EB%94%A5%EB%9F%AC%EB%8B%9D%20%EC%8B%AC%ED%99%94/Document/Dog_Cat_Classification/Dog_Cat_Classification.md)



### 5. [Multi Class Classification](https://github.com/sanga327/KSA/tree/main/Module06.%20%EB%94%A5%EB%9F%AC%EB%8B%9D%20%EC%8B%AC%ED%99%94/Document/MULTI_CLASS/Multi_Class_Classification.md)



### 6. [CNN Architecture](https://github.com/sanga327/KSA/tree/main/Module06.%20%EB%94%A5%EB%9F%AC%EB%8B%9D%20%EC%8B%AC%ED%99%94/Document/CNN_Architecture/CNN_Architecture.md)

<br>

---

### 환경구축

- CPU 버전(tensorflow 2.1 keras 2.2.4)
  - conda install tensorflow=2.1
  - pip install keras==2.2.4
- GPU 버전(tensorflow-gpu 2.1  keras 2.2.4) GPU 2000 series 이하
  - conda install -c anaconda cudatooklit=10.1 keras-gpu=2.2.4

- Jupyter notebook

  - pip install ipykernel
  - Python -m ipykernel install --user --name [가상환경명] --display-name “[표시할 이름]”

  |                | **주피터노트북**(jupyter  **notebook)** | **파이참**(Pycharm) |
  | -------------- | --------------------------------------- | ------------------- |
  | 디버깅         | X                                       | O                   |
  | 파이썬(python) | O                                       | O                   |
  | Tensorflow     | O                                       | O                   |
  | Keras          | O                                       | O                   |
  | 페이지 사용    | 메모, 코드, 주석                        | Only 코드,  주석    |

<br>

### keras를 이용한 딥러닝 개발

- 문제 유형별 손실 함수 및 출력층의 활성화 함수

  | **문제 유형**             | **출력층의** **활성화 함수** | **손실 함수**                  |
  | ------------------------- | ---------------------------- | ------------------------------ |
  | 이진 분류                 | Sigmoid                      | binary_crossentropy            |
  | 다중 분류                 | Softmax                      | categorical_crossentropy       |
  | 임의 값에 대한 회귀       | -                            | MSE                            |
  | 0과 1사이  값에 대한 회귀 | Sigmoid                      | MSE  또는  binary_crossentropy |

<br>

---

### CNN 개요 및 구현

#### - 작업 순서

1. 이미지 불러오기
2. 모델 설계
3. 모델 컴파일 (loss 함수 설정, optimizer 설정)
4. 학습
5. 학습 완료 된 모델 성능 평가 (정확도, loss값)

<br>

####  - keras를 이용한 네트워크 구현 방식

- Sequential 클래스
  - 층(layer)를 순차적으로만 쌓은 네트워크에 적합
- 함수형(Functional) API
  - 병렬 층이 존재하고 입력 또는 출력이 여러 개인 경우에 적합

<br>

---
### 1. CNN

#### CNN 개요 및 구현

- 데이터 분리

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210523190710931.png">

<br>

---

#### CNN(Convolutional Neural Network)

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210523190926866.png" >



---

#### 합성곱 - Convolution 연산

[단계 1]

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210523190941890.png" >



[단계 2]

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210523191025216.png" >

... 

[단계 9]

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210523191046258.png" >



<br>

#### 1) Stride

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210523191328341.png" >

- filter를 계속 돌면 입력 이미지가 작아지므로 정보를 잃어버리는 문제 발생

<br>

#### 2) Padding

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210523192137409.png" >



<br>

#### 3) Pooling

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530163517485.png" >

<br>

- Pooling의 종류
  - Max Pooling: 정해진 filter 크기 안에서 가장 큰 값을 뽑아낸다.
  - Average Pooling: 정해진 filter 크기 안의 평균을 뽑아낸다.
  
- 보통의 경우 Max Pooling을 더 자주 사용한다. 
  - 왜? Pooling의 목적은 filter마다 특징을 찾아내는 것인데, feature maps에서 큰 숫자가 filter가 찾아내고자 하는 특징에 가깝다.

- Pooling의 목적
  - input size 줄임: convolution 연산을 반복하게 되는데, 특징만 뽑아내서 중요한 부분만 학습하는 것이 합리적이다.
  - overfitting 조절: input size가 줄어드는 것은 그만큼 쓸데없는 parameter의 수가 줄어드는 것
  - 특징을 잘 뽑아냄: pooling을 했을 때 특정한 모양을 더 잘 인식할 수 있음

- tf.keras.layers.MaxPooling2D

  -  `pool_size` : pooling에 사용할 filter의 크기를 정하는 것.(단순한 정수, 또는 튜플형태 (N,N))
  -  `strides`   : pooling에 사용할 filter의 strides를 정하는 것
  -  `padding`  : `valid`(=padding을 안하는것) or `same`(=pooling결과 size가 input size와 동일하게 padding)

  ```python
  tf.keras.layers.MaxPool2D(
      pool_size=(2, 2), 
      strides=None, 
      padding='valid', 
      data_format=None, 
      **kwargs
  )
  ```


---

### 2. DNN

#### Activation Function

#### 1) Sigmoid

- Binary

#### 2) Softmax

- Multinomial

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530140348016.png">

   <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530140355725.png">



<br>

#### Dropout

- 랜덤하게 노드를 죽이는 것

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530140837001.png">

<br>

#### BatchNormalization

- Internal Covariate Shift(공분산 이동)문제로 학습속도 느림

- 해결방안

  - Initialization 잘하기 -> 어렵다!
  - small learning rate -> local point에 빠지게 된다.
  - 활성화함수(ReLU 또는 Sigmoid)에 들어가기 전에 BN 해서 스케일을 줄인다.

- 보통 mean:0, variance:1로 해준다.

- Layer 기준이 아닌 node를 기준으로 한다. 

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530142501384.png">
  
  

---

#### 일반적인 딥러닝 작업 순서

1. 데이터 전처리
2. 네트워크 정의
3. 손실 함수, 옵티마이저, 성능 지표 설정
4. 모델 학습
5. 모델 평가 및 분석

---

#### 학습하면서 직면하는 문제

**1. 과소적합(underfitting)과 과대적합(overfitting)**

- 오버피팅

  - 학습 모델이 train data set에 fit
  
  - test 데이터나 실제 데이터 사용시 오류
  
    <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530140658332.png">
  
  

- 오버피팅 줄이는 방법
  - 많은 train data 보유
  - feature 개수 줄이기
  - 일반화

<br>

