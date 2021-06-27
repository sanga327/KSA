# Multi Class Classification

### 1. 데이터 정보

- Airplane, car, cat, dog, flower, fruit, motorbike, person 총 8개

<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530162657672.png">

---

### 2. 모델링

```python
def define_model():
    model = Sequential()
    model.add(Conv2D(32, (3, 3), activation='relu', kernel_initializer='he_normal', padding='same', input_shape=(200, 200, 3)))
    model.add(BatchNormalization())
    #model.add(MaxPooling2D((2, 2)))
    model.add(Conv2D(64, (3, 3), activation='relu', kernel_initializer='he_normal', padding='same'))
    model.add(MaxPooling2D((2, 2)))
    model.add(Conv2D(128, (3, 3), activation='relu', kernel_initializer='he_normal', padding='same'))
    model.add(BatchNormalization())
    model.add(Conv2D(128, (3, 3), activation='relu', kernel_initializer='he_normal', padding='same'))
    model.add(MaxPooling2D((2, 2)))
    model.add(Conv2D(256, (3, 3), activation='relu', kernel_initializer='he_normal', padding='same'))
    model.add(BatchNormalization())
    model.add(Conv2D(256, (3, 3), activation='relu', kernel_initializer='he_normal', padding='same'))
    model.add(MaxPooling2D((2, 2)))
    model.add(Conv2D(512, (3, 3), activation='relu', kernel_initializer='he_normal', padding='same'))
    model.add(BatchNormalization())
    model.add(Conv2D(512, (3, 3), activation='relu', kernel_initializer='he_normal', padding='same'))
    model.add(MaxPooling2D((5, 5)))

    model.add(Flatten())
    model.add(Dense(3000, activation='relu', kernel_initializer='he_normal'))
    model.add(Dropout(0.3))
    model.add(Dense(2000, activation='relu', kernel_initializer='he_normal'))
    model.add(Dropout(0.3))
    model.add(Dense(1000, activation='relu', kernel_initializer='he_normal'))
    model.add(Dropout(0.3))
    model.add(Dense(8, activation='softmax'))
    # compile model
    #opt = Adam(lr=0.001, momentum=0.9)
    model.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])
    return model

model = define_model()
```
<img src = "https://github.com/sanga327/KSA/blob/main/Module06. 딥러닝 심화/Image/image-20210530162612946.png">

