from tensorflow.keras.datasets import cifar10
from tensorflow.keras.models import Model, Sequential
from tensorflow.keras.layers import Dense, Input, Conv2D, Activation, MaxPooling2D, Flatten, BatchNormalization, Dropout, LeakyReLU
import matplotlib.pyplot as plt
from keras.utils import to_categorical
import numpy as np
from keras import backend as K
from tensorflow.keras.preprocessing.image import ImageDataGenerator
import os  # 경로 알아오기 위한 package
from keras.regularizers import l2





def build_model(img_height, img_width, img_channel, class_count, weight_decay):
    input_layer = Input(shape=(img_height, img_width, img_channel))
    x = Conv2D(filters=64, kernel_size=(3, 3), padding='same',   # padding해서 사이즈 1/2 되었으므로
               kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
               activation='relu', name='Conv2D_1')(input_layer)
    x = Conv2D(filters=64, kernel_size=(3, 3), padding='same',
               kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
               activation='relu', name='Conv2D_2')(x)
    x = MaxPooling2D(pool_size=(3, 3), strides=(2, 2))(x)

    x = Conv2D(filters=128, kernel_size=(3, 3), padding='same',
               kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
               activation='relu', name='Conv2D_3')(x)
    x = Conv2D(filters=128, kernel_size=(3, 3), padding='same',
               kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
               activation='relu', name='Conv2D_4')(x)
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2))(x)

    x = Conv2D(filters=256, kernel_size=(3, 3), padding='same',
               kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
               activation='relu', name='Conv2D_5')(x)
    x = Conv2D(filters=256, kernel_size=(3, 3), padding='same',
               kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
               activation='relu', name='Conv2D_6')(x)
    x = Conv2D(filters=256, kernel_size=(3, 3), padding='same',
               kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
               activation='relu', name='Conv2D_7')(x)
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2))(x)

    x = Conv2D(filters=512, kernel_size=(3, 3), padding='same',
               kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
               activation='relu', name='Conv2D_8')(x)
    x = Conv2D(filters=512, kernel_size=(3, 3), padding='same',
               kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
               activation='relu', name='Conv2D_9')(x)
    x = Conv2D(filters=512, kernel_size=(3, 3), padding='same',
               kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
               activation='relu', name='Conv2D_10')(x)
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2))(x)

    x = Conv2D(filters=512, kernel_size=(3, 3), padding='same',
               kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
               activation='relu', name='Conv2D_11')(x)
    x = Conv2D(filters=512, kernel_size=(3, 3), padding='same',
               kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
               activation='relu', name='Conv2D_12')(x)
    x = Conv2D(filters=512, kernel_size=(3, 3), padding='same',
               kernel_initializer='he_normal', kernel_regularizer=l2(weight_decay),
               activation='relu', name='Conv2D_13')(x)
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2))(x)  # 7X7

    x = Flatten()(x)

    x = Dense(4096, activation='relu')(x)
    x = Dense(4096, activation='relu')(x)
    output_layer = Dense(1000, activation='softmax')(x)

    model = Model(input_layer, output_layer)
    return model

model_build = build_model(224, 224, 3, 1000, 1e-4)
model_build.summary()



# 교수님 답

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
model_build.summary()