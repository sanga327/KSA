from tensorflow.keras.datasets import cifar10
from tensorflow.keras.models import Model, Sequential
from tensorflow.keras.layers import Dense, Input, Conv2D, Activation, MaxPooling2D, Flatten, BatchNormalization, Dropout
import matplotlib.pyplot as plt
from keras.utils import to_categorical
import numpy as np


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
# 그래프로 확인해 보자.
# plt.imshow(x_train[1000], interpolation='bicubic') # 출력할 index 임의로 가져옴
# tmp = "Label:"+str(actual_single[1000])
# plt.title(tmp, fontsize=30)
# plt.tight_layout()
# plt.show()

####################################
NUM_CLASSES = 10
batch_size = 30
epochs = 30

x_train = x_train.astype('float32')/255
x_test = x_test.astype('float32')/255
y_train = to_categorical(y_train, NUM_CLASSES)
y_test = to_categorical(y_test, NUM_CLASSES)

####################################
# 모델 정의 부분(DNN)
# unit=200, Dense=3 (출력층 포함 3개)
# input_layer = Input(shape=(3072,), name='input_layer')  # 3072 = 32*32*3 # 이렇게 하면 flatten 안해도 된다.
input_layer = Input(shape=(32, 32, 3))
x = Flatten()(input_layer)
x = Dense(units=200, activation='relu')(x)
x = Dense(units=200, activation='relu')(x)
output_layer = Dense(units=10, activation='softmax')(x)
model = Model(inputs=input_layer, outputs=output_layer)

####################################
# 모델 컴파일
model.compile(loss='categorical_crossentropy', optimizer='Adam', metrics=['accuracy'])   # sgd, rms 등 사용 가능

####################################
# 모델 훈련
history = model.fit(x_train, y_train, epochs=epochs,
                    batch_size=batch_size, verbose=1, validation_split=0.2)

####################################
# 모델 평가
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










