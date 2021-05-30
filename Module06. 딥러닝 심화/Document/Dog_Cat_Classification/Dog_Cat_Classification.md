# Dog & Cat Classification



### 1. 데이터 설명

- 개와 고양이 이미지 데이터셋

- [Kaggle - Dogs vs. Cats](https://www.kaggle.com/c/dogs-vs-cats)

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530151917279.png">

<br>

----

### 2. 데이터 전처리

#### 1) 데이터셋 분리

- train, test 데이터셋으로 분리되어있음

- validation을 위한 데이터셋 구축 위한 코드

  ```python
  import shutil
  from random import seed
  from random import random
  import os
  
  def createFolder(directory):
      try:
          if not os.path.exists(directory):
              os.makedirs(directory)
      except OSError:
          print('Error: Creating directory. ' + directory)
  
  def search(dirname):
      img_list = []
      for (path, dir, files) in os.walk(dirname):
          for filename in files:
              ext = os.path.splitext(filename)[-1]
              if ext == '.jpg':
                  img_list.append(path+'/'+filename)
      return img_list
  
  img_list = search("dog_cat_test_data/train")
  val_ratio = 0.25
  
  data_set = './data_dog_cat/'
  subdirs = ['train/', 'val/']
  labeldirs = ['dogs/', 'cats/']
  for sub in subdirs:
      for labelsub in labeldirs:
          dir_name = data_set + sub + labelsub
          # print(dir_name)
          createFolder(dir_name)
  
  for i, img in enumerate(img_list):
      dst_dir = 'train/'
      if random() < val_ratio:
          dst_dir = 'val/'
      if img_list[i].split('/')[-1].find('cat') >= 0:
          dst = data_set + dst_dir + 'cats/' + img_list[i].split('/')[-1]
          shutil.copy(img, dst)
      elif img_list[i].split('/')[-1].find('dog') >= 0:
          dst = data_set + dst_dir + 'dogs/' + img_list[i].split('/')[-1]
          shutil.copy(img, dst)
  ```

  

#### 2) data augmentation

- 데이터 증강

- 주로 Imbalance한 데이터셋을 이용하여 딥러닝 모델을 구축할 때 사용
- 데이터셋이 너무 적은 경우 overfitting와 학습이 제대로 되지 않는 문제 발생 -> 이러한 문제 해결

- **ImageDataGenerator** 사용

```python
from keras.preprocessing.image import ImageDataGenerator

# create data generators
train_datagen = ImageDataGenerator(rescale=1.0 / 255.0,
                                   width_shift_range=0.1, height_shift_range=0.1, horizontal_flip=True)
test_datagen = ImageDataGenerator(rescale=1.0 / 255.0)

train_it = train_datagen.flow_from_directory('data_dog_cat/train/',
                                       class_mode='binary', batch_size=64, target_size=(200, 200))
val_it = test_datagen.flow_from_directory('data_dog_cat/val/',
                                     class_mode='binary', batch_size=64, target_size=(200, 200))
test_it = test_datagen.flow_from_directory('data_dog_cat/test/',
                                     class_mode='binary', batch_size=64, target_size=(200, 200))
```

- **Horizontal & Vertical Shift Augmentation**
  - 이미지 이동
  - **width_shift_range**: 좌우 이동
  - **height_shift_range**: 위아래 이동
- **Horizontal & Vertical Flip Augmentation**
  - 이미지 뒤집기
  - **horizonal_flip = True**: 좌우 뒤집힘
  - **vertical_flip = True**: 위아래 뒤집힘

- **Random Rotation Augmentation**

  - 이미지를 랜덤한 각도로 회전

- **Random Brightness Augmentation**

  - 이미지의 밝기를 랜덤하게 다르게 줌

- **Random Zoom Augmentation**

  - 이미지를 랜덤하게 Zoom

  <br>

---

### 3. 모델링

```python
def define_model():
    model = Sequential()
    model.add(Conv2D(32, (3, 3), activation='relu', kernel_initializer='he_normal', padding='same', input_shape=(200, 200, 3)))
    model.add(MaxPooling2D((2, 2)))
    model.add(Conv2D(64, (3, 3), activation='relu', kernel_initializer='he_normal', padding='same'))
    model.add(MaxPooling2D((2, 2)))
    model.add(Conv2D(128, (3, 3), activation='relu', kernel_initializer='he_normal', padding='same'))
    model.add(MaxPooling2D((2, 2)))
    model.add(Flatten())
    model.add(Dense(128, activation='relu', kernel_initializer='he_normal'))
    model.add(Dense(1, activation='sigmoid'))
    # compile model
    opt = SGD(lr=0.001, momentum=0.9)
    model.compile(optimizer=opt, loss='binary_crossentropy', metrics=['accuracy'])
    return model

model = define_model()
```



<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530151317422.png">