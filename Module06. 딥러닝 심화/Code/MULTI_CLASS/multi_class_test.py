# make a prediction for a new image.
from tensorflow.keras.preprocessing.image import load_img
from tensorflow.keras.preprocessing.image import img_to_array
from tensorflow.keras.models import load_model
import matplotlib.pyplot as plt
import numpy as np
from tensorflow.keras.preprocessing.image import ImageDataGenerator
import os


def search(dirname):
    img_list = []
    for (path, dir, files) in os.walk(dirname):
        for filename in files:
            ext = os.path.splitext(filename)[-1]
            if ext == '.jpg':
                img_list.append(path+'/'+filename)
    return img_list

# load and prepare the image / 경로에서 가져온 이미지를 배열(list) 형태로 입력
def load_image(filename):
    # load the image
    img = load_img(filename, target_size=(200, 200))
    # convert to array
    img = img_to_array(img)
    # reshape into a single sample with 3 channels
    img = np.expand_dims(img, axis=0)
    # img scaling
    img /= 255

    return img

img_list_1 = search('./test_img_multi')  # test_img 폴더 생성

# data load 및 acc하는 부분
model = load_model('./saved_model/multi_class_final_model.h5')
model.summary()

test_datagen = ImageDataGenerator(rescale=1.0 / 255.0)
test_it = test_datagen.flow_from_directory('/8-multi-class_data/preprocessed_images/test/',
                                     class_mode='categorical', batch_size=64, target_size=(200, 200))
# evaluate model
_, acc = model.evaluate_generator(test_it, steps=len(test_it), verbose=1)
print('>accuracy : %.3f' % (acc * 100.0))

classes = np.array(['airplane', 'car', 'cat', 'dog', 'flower', 'fruit', 'motorbike', 'person'])
for i in img_list_1:
    img = load_image(i)
    # predict the class
    result = model.predict(img)
    preds_value = classes[np.argmax(result, axis=-1)]

    tmp = "predict:" + str(preds_value)
    model_acc = "model_acc:" + str(acc * 100.0)
    plt.figure(figsize=(10, 10))
    plt.title(tmp)
    plt.xlabel(model_acc, fontsize=20)
    plt.imshow(img[0])
    plt.show()

