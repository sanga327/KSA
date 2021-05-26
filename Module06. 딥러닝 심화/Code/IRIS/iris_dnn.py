from sklearn import datasets
from tensorflow.keras.models import Sequential, Model
from tensorflow.keras.layers import Dense, Input
import matplotlib.pyplot as plt
from keras.utils import to_categorical
from sklearn.utils import shuffle
from sklearn.model_selection import train_test_split

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


# iris 데이터 import
iris = datasets.load_iris()
X = iris.data
Y = iris.target

dataset_y = to_categorical(Y)
dataset_x = X
dataset_x, dataset_y = shuffle(dataset_x, dataset_y)

x_train = dataset_x[:120]
x_test = dataset_x[120:]
y_train = dataset_y[:120]
y_test = dataset_y[120:]

model = Sequential()
model.add(Dense(64, input_shape=(4,), activation='relu'))  # input이 4개이므로
model.add(Dense(64, activation='relu'))
model.add(Dense(3, activation='softmax'))

model.compile(loss='categorical_crossentropy', optimizer='Adam', metrics=['accuracy'])  # softmax이므로 loss
# model.summary()

history = model.fit(x_train, y_train, validation_data=(x_test, y_test), epochs=100)  # val을 따로 빼놓지 않아 여기서 만들어준다.

print("\n")
print('test start')
score = model.evaluate(x_test, y_test, verbose=0)  # 0: 학습내역 안보임 / 보고싶으면 1 입력
print('test loss:', score[0])
print('test acc', score[1])

plot_loss(history)
plt.show()
plot_acc(history)
plt.show()

