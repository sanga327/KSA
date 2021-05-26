from tensorflow.keras.datasets import cifar10
from tensorflow.keras.models import Model, Sequential
from tensorflow.keras.layers import Dense, Input, Conv2D, Activation, MaxPooling2D, Flatten, BatchNormalization, Dropout, LeakyReLU
import matplotlib.pyplot as plt
from keras.utils import to_categorical
import numpy as np
from keras import backend as K
from tensorflow.keras.preprocessing.image import ImageDataGenerator
import os  # 경로 알아오기 위한 package

# 모델 저장
save_dir = os.path.join(os.getcwd(), 'saved_model')
model_name = 'keras_cifar10_aug_trained_model.h5'  # .h5 / .hdf5 -> keras 대용량 파일 저장


# loss 그래프 그리기
def plot_loss(history):
    plt.plot(history.history['loss'])
    plt.plot(history.history['val_loss'])
    plt.title('Model loss')
    plt.ylabel('Loss')
    plt.xlabel('Epochs')
    plt.legend(['Train', 'val'], loc=0)

# accuracy 그래프 그리기
def plot_acc(history):
    plt.plot(history.history['accuracy'])
    plt.plot(history.history['val_accuracy'])
    plt.title('Model accuracy')
    plt.ylabel('accuracy')
    plt.xlabel('Epochs')
    plt.legend(['Train', 'val'], loc=0)


(x_train, y_train), (x_test, y_test) = cifar10.load_data()

CLASSES = np.array(['airplane', 'automobile', 'bird', 'cat', 'deer', 'dog', 'frog', 'horse', 'ship', 'truck'])  # class label 부여
actual_single = CLASSES[y_train]

####################################
img_rows, img_cols = 32, 32
if K.image_dim_ordering() == 'th':
    X_train = x_train.reshape(x_train.shape[0], 3, img_rows, img_cols)
    X_test = x_test.reshape(x_test.shape[0], 3, img_rows, img_cols)
    input_shape = (3, img_rows, img_cols)
else:
    X_train = x_train.reshape(x_train.shape[0], img_rows, img_cols, 3)
    X_test = x_test.reshape(x_test.shape[0], img_rows, img_cols, 3)
    input_shape = (img_rows, img_cols, 3)  # 높이 너비 채널

####################################
NUM_CLASSES = 10
batch_size = 10
epochs = 10

x_train = x_train.astype('float32')/255
x_test = x_test.astype('float32')/255
y_train = to_categorical(y_train, NUM_CLASSES)
y_test = to_categorical(y_test, NUM_CLASSES)

####################################
# 모델 정의
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
model.summary()

model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy'])

# data aug
datagen = ImageDataGenerator(
    rotation_range=0.1,
    width_shift_range=0.1,
    height_shift_range=0.1,
    horizontal_flip=True)

# 모델 학습 (aug 적용)
history = model.fit_generator(datagen.flow(x_train, y_train, batch_size=16),   # generator로 들어가는 것
                              steps_per_epoch=x_train.shape[0]/16, epochs=epochs, # x_train.shape[0]: 보통 train 데이터 나누기 batch size한다.
                              validation_data=(x_test, y_test), workers=4)

# 모델 저장
if not os.path.join(save_dir):
    os.makedirs(save_dir)
model_path = os.path.join(save_dir, model_name)
model.save(model_path)

####################################
# predict
print('Test start')
score = model.evaluate(x_test, y_test, batch_size=batch_size)
print('\nTest loss:', score[0])
print('Test acc:', score[1])

####################################
# 학습된 loss값과 acc를 보기 위한 그래프
plot_loss(history)
plt.show()
plot_acc(history)
plt.show()
