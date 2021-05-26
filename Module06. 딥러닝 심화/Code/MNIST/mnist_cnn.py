from tensorflow.keras.datasets import mnist
from tensorflow.keras.models import Model, Sequential
from tensorflow.keras.layers import Dense, Input, Conv2D, Activation, MaxPooling2D, Flatten, BatchNormalization, Dropout
import matplotlib.pyplot as plt
from keras.utils import to_categorical
import numpy as np
from keras import backend as K

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


# 하이퍼파라미터 설정
batch_size = 128
num_classes = 10
epochs = 12

# 입력 이미지 사이즈 정보
img_rows, img_cols = 28, 28
nb_filters = 32


# 데이터 로드
(X_train, y_train), (X_test, y_test) = mnist.load_data()
# print(X_train.shape[0])
# print(X_train.shape[1])
# print(X_train.shape[2])

if K.image_dim_ordering() == 'th':
    X_train = X_train.reshape(X_train.shape[0], 1, img_rows, img_cols)
    X_test = X_test.reshape(X_test.shape[0], 1, img_rows, img_cols)
    input_shape = (1, img_rows, img_cols)
else:
    X_train = X_train.reshape(X_train.shape[0], img_rows, img_cols, 1)
    X_test = X_test.reshape(X_test.shape[0], img_rows, img_cols, 1)
    input_shape = (img_rows, img_cols, 1)  # 높이 너비 채널


# 데이터 정규화
X_train = X_train.astype('float32')
X_test = X_test.astype('float32')
X_train /= 255
X_test /= 255


# 라벨
y_train = to_categorical(y_train, num_classes)   # 0-9값을 one-hot 인코딩으로 바꿔준다.
y_test = to_categorical(y_test, num_classes)


# 네트워크 정의
input_tensor = Input(shape=input_shape)
x = Conv2D(32, kernel_size=(3, 3), padding='valid', name='Conv1')(input_tensor)
# BatchNormal과 Dropout을 연속으로 붙여서 사용하지 않는다.
x = BatchNormalization()(x) # 보통 activation 함수 들어가기 전에 사용해서 스케일을 줄인다.

x = Activation('relu', name='relu_1')(x)
x = Conv2D(32, kernel_size=(3, 3), padding='valid', name='Conv2')(x)
x = Activation('relu', name='relu_2')(x)
x = MaxPooling2D(pool_size=(2, 2), name='pool_1')(x)
x = Flatten()(x)    # 펴준다
x = Dense(units=128, name='hidden_1')(x)
x = Dropout(0.5)(x)  # train이라 0.5 사용 test일때는 1  # units=10 밑에 쓰면 10을 0.5하므로 위에서 해주는것이 좋다
x = Activation('relu', name='relu_3')(x)
x = Dense(units=10, name='hidden_2')(x)   # 0-9로 10개의 값을 출력할 것임을 명시해줌
output_tensor = Activation('softmax', name='output_tensor')(x)
model = Model(inputs=input_tensor, outputs=output_tensor)
model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy'])

# 학습
history = model.fit(X_train, y_train, batch_size=batch_size,
                    epochs=epochs, verbose=1, validation_split=0.2)
                    # train 전체 데이터 중 0.2만큼 validation으로 활용 (training 60%, Val 20%, test 20%)

# predict
print('Test start')
score = model.evaluate(X_test, y_test, batch_size=batch_size)
print('\nTest loss:', score[0])
print('Test acc:', score[1])

# 학습된 loss값과 acc를 보기 위한 그래프
plot_loss(history)
plt.show()
plot_acc(history)
plt.show()




