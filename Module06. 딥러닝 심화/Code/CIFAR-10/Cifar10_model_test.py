import matplotlib.pyplot as plt
import numpy as np
from tensorflow.keras.datasets import cifar10
from tensorflow.keras.models import load_model
from tensorflow.keras.utils import to_categorical

# 데이터 로드
(x_train, y_train), (x_test, y_test) = cifar10.load_data()
x_train - x_train.astype('float32')/255.0
x_test = x_test.astype('float32')/255.0
y_train = to_categorical(y_train, 10)
y_test = to_categorical(y_test, 10)

# 모델 불러오기
model = load_model('saved_model/keras_cifar10_aug_trained_model.h5')
model.summary()

# test 결과 또는 정확도 측정
print('\n')
print('test start')
score = model.evaluate(x_test, y_test)
print('test loss: ', score[0])
print('test acc: ', score[1])



# 학습모델 결과를 이미지로 출력하기
CLASSES = np.array(['airplane', 'automobile', 'bird', 'cat', 'deer', 'dog', 'frog', 'horse', 'ship', 'truck'])  # class label 부여

preds = model.predict(x_test)
preds_single = CLASSES[np.argmax(preds, axis=-1)]
actual_single = CLASSES[np.argmax(y_test, axis=-1)]

# plot 그림 그리는 부분
n_to_show = 10
indices = np.random.choice(range(len(x_test)), n_to_show)

fig = plt.figure(figsize=(15, 3))
fig.subplots_adjust(hspace=0.4, wspace=0.4)

for i, idx in enumerate(indices):
    img = x_test[idx]
    ax = fig.add_subplot(1, n_to_show, i+1)
    ax.axis('off')
    ax.text(0.5, -0.35, 'pred='+str(preds_single[idx]), fontsize=10, ha='center', transform=ax.transAxes)
    ax.text(0.5, -0.7, 'act=' + str(actual_single[idx]), fontsize=10, ha='center', transform=ax.transAxes)
    ax.imshow(img)

plt.show()



























