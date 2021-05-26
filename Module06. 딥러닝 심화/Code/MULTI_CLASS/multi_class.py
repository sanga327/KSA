from tensorflow.keras import Sequential
from tensorflow.keras.layers import Conv2D, MaxPooling2D, Flatten, Dense, BatchNormalization, Dropout
from tensorflow.keras.optimizers import SGD
import matplotlib.pyplot as plt

def plot_loss(history):
    plt.plot(history.history['loss'])
    plt.plot(history.history['val_loss'])
    plt.title('Model Loss')
    plt.ylabel('Loss')
    plt.xlabel('Epochs')
    plt.legend(['Train', 'val'], loc=0)

# accuracy 그래프 그리는 함수
def plot_acc(history):
    plt.plot(history.history['accuracy'])
    plt.plot(history.history['val_accuracy'])
    plt.title('Model accuracy')
    plt.ylabel('Accuracy')
    plt.xlabel('Epochs')
    plt.legend(['Train', 'val'], loc=0)

# define cnn model
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

from keras.preprocessing.image import ImageDataGenerator

# create data generators
train_datagen = ImageDataGenerator(rescale=1.0 / 255.0,
                                   width_shift_range=0.1, height_shift_range=0.1, horizontal_flip=True)
test_datagen = ImageDataGenerator(rescale=1.0 / 255.0)

train_it = train_datagen.flow_from_directory('8-multi-class_data/preprocessed_images/train/',
                                       class_mode='categorical', batch_size=64, target_size=(200, 200))
val_it = test_datagen.flow_from_directory('8-multi-class_data/preprocessed_images/val/',
                                     class_mode='categorical', batch_size=64, target_size=(200, 200))
test_it = test_datagen.flow_from_directory('8-multi-class_data/preprocessed_images/test/',
                                     class_mode='categorical', batch_size=64, target_size=(200, 200))

# fit model
history = model.fit_generator(train_it, steps_per_epoch=len(train_it),
                              validation_data=val_it, validation_steps=len(val_it), epochs=20, verbose=1)

# evaluate model
_, acc = model.evaluate_generator(test_it, steps=len(test_it), verbose=1)
print('>accuracy : %.3f' % (acc * 100.0))

# save model
model.save('./saved_model/multi_class_final_model.h5')

plot_loss(history)
plt.show()
plot_acc(history)
plt.show()