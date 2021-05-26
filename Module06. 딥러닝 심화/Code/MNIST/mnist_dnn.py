from tensorflow.keras.datasets import mnist
from tensorflow.keras.models import Model, Sequential
from tensorflow.keras.layers import Dense, Input
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

# 하이퍼파라미터 설정
batch_size = 128
num_classes = 10
epochs = 12

# 데이터 로드
(X_train, y_train), (X_test, y_test) = mnist.load_data()

# mnist 데이터 이미지 추출 부분 확인
# plt.figure(figsize=(10,10))
# for i in range(25):
#     plt.subplot(5, 5, i+1)
#     plt.xticks([])
#     plt.yticks([])
#     plt.grid(False)
#     plt.imshow(np.reshape(X_train[i], [28, 28]), cmap='Greys')
#     plt.xlabel(y_train[i])
# plt.show()

L, W, H = X_train.shape
X_train = X_train.reshape(60000, W*H)
X_test = X_test.reshape(10000, W*H)

X_train = X_train.astype('float32')
X_test = X_test.astype('float32')
X_train /= 255
X_test /= 255

# 라벨
# print('y_train_ori:{}'.format(y_train[:5]))
y_train = to_categorical(y_train, num_classes)   # 0-9값을 one-hot 인코딩으로 바꿔준다.
# print('y_train_after:{}'.format(y_train[:5]))
y_test = to_categorical(y_test, num_classes)

# 네트워크 정의
# function()
input_tensor = Input(shape=(784,), name='input_tensor')  # name 설정하면 나중에 편하게 볼 수 있다.
hidden_1 = Dense(units=256, activation='sigmoid', name='hidden_1')(input_tensor)
hidden_2 = Dense(units=256, activation='sigmoid', name='hidden_2')(hidden_1)
hidden_3 = Dense(units=256, activation='sigmoid', name='hidden_3')(hidden_2)
hidden_4 = Dense(units=256, activation='sigmoid', name='hidden_4')(hidden_3)
output_tensor = Dense(num_classes, activation='softmax', name='output_tensor')(hidden_4)  # 결과가 binary라면 sigmoid로 바꿔줘야 한다.
model = Model(inputs=input_tensor, outputs=output_tensor)
model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy']) # sgd, rms 등 사용 가능
model.summary()

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




# sequential()









