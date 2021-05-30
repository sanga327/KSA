# CNN Architecture

### 1. VGG-NET

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530145933873.png">

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530145943217.png">

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530145950289.png">

<br>

- 모델 설계(VGG-16)

  ```python
  def build_model_16(img_height, img_width, img_channel, class_count, weight_decay):
      input_layer = Input(shape=(img_height, img_width, img_channel))
      x = Conv2D(filters=64, kernel_size=(3, 3), stride=1, padding='same',   # padding해서 사이즈 1/2 되었으므로
                 kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
                 activation='relu', name='Conv2D_1')(input_layer)
      x = Conv2D(filters=64, kernel_size=(3, 3), padding='same',
                 kernel_initializer='he_normal', stride=1, kernel_regularizer=l2(weight_decay),
                 activation='relu', name='Conv2D_2')(x)
      x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2))(x)
  
  
      x = Conv2D(filters=128, kernel_size=(3, 3), stride=1, padding='same',   # padding해서 사이즈 1/2 되었으므로
                 kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
                 activation='relu', name='Conv2D_3')(x)
      x = Conv2D(filters=128, kernel_size=(3, 3), padding='same',
                 kernel_initializer='he_normal', stride=1, kernel_regularizer=l2(weight_decay),
                 activation='relu', name='Conv2D_4')(x)
      x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2))(x)
  
      x = Conv2D(filters=256, kernel_size=(3, 3), stride=1, padding='same',   # padding해서 사이즈 1/2 되었으므로
                 kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
                 activation='relu', name='Conv2D_5')(x)
      x = Conv2D(filters=256, kernel_size=(3, 3), padding='same',
                 kernel_initializer='he_normal', stride=1, kernel_regularizer=l2(weight_decay),
                 activation='relu', name='Conv2D_6')(x)
      x = Conv2D(filters=256, kernel_size=(3, 3), padding='same',
                 kernel_initializer='he_normal', stride=1, kernel_regularizer=l2(weight_decay),
                 activation='relu', name='Conv2D_7')(x)
      x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2))(x)
  
      x = Conv2D(filters=512, kernel_size=(3, 3), stride=1, padding='same',   # padding해서 사이즈 1/2 되었으므로
                 kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
                 activation='relu', name='Conv2D_5')(x)
      x = Conv2D(filters=512, kernel_size=(3, 3), padding='same',
                 kernel_initializer='he_normal', stride=1, kernel_regularizer=l2(weight_decay),
                 activation='relu', name='Conv2D_6')(x)
      x = Conv2D(filters=512, kernel_size=(3, 3), padding='same',
                 kernel_initializer='he_normal', stride=1, kernel_regularizer=l2(weight_decay),
                 activation='relu', name='Conv2D_7')(x)
      x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2))(x)
  
      x = Flatten()(x)
  
      x = Dense(4096, activation='relu', name='fc1')(x)
      x = Dense(4096, activation='relu', name='fc2')(x)
      output_layer = Dense(class_count, activation='softmax')(x)
  
      model = Model(input_layer, output_layer)
      return model
  
  
  model_build = build_model(224, 224, 3, 1000, 1e-4)
  ```

  

  <img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530150331802.png">



---

### 2. ResNet



<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530150757931.png">

<br>

---

### 3. DenseNet

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530150741069.png">

<br>

- CNN vs ResNet vs DenseNet

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530150806099.png">

![](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20210530150806099.png)

<br>

---

### 4. AlexNet

```python
def build_model(img_height, img_width, img_channel, class_count, weight_decay):
    input_layer = Input(shape=(img_height, img_width, img_channel))
    x = Conv2D(filters=96, kernel_size=(11, 11), strides=4, padding='valid',
               kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
               activation='relu', name='Conv2D_1')(input_layer)
    x = MaxPooling2D(pool_size=(3, 3), strides=(2, 2))(x)
    x = BatchNormalization()(x)
    x = Conv2D(filters=256, kernel_size=(5, 5), strides=1, padding='same',
               kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
               activation='relu', name='Conv2D_2')(x)
    x = MaxPooling2D(pool_size=(3, 3), strides=(2, 2))(x)
    x = BatchNormalization()(x)
    x = Conv2D(filters=384, kernel_size=(3, 3), strides=1, padding='same',
               kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
               activation='relu', name='Conv2D_3')(x)
    x = Conv2D(filters=384, kernel_size=(3, 3), strides=1, padding='same',
               kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
               activation='relu', name='Conv2D_4')(x)
    x = Conv2D(filters=256, kernel_size=(3, 3), strides=1, padding='same',
               kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
               activation='relu', name='Conv2D_5')(x)
    x = MaxPooling2D(pool_size=(3, 3), strides=(2, 2))(x)
    x = Flatten()(x)

    x = Dense(4096, activation='relu')(x)
    x = Dense(4096, activation='relu')(x)
    output_layer = Dense(1000, activation='softmax')(x)

    model = Model(input_layer, output_layer)
    return model

model_build = build_model(227, 227, 3, 1000, 1e-4)
```

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530150110376.png">

