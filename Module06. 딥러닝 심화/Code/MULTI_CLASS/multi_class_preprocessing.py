import shutil
from random import seed
from random import random
import os

def createFolder(directory):
    try:
        if not os.path.exists(directory):
            os.makedirs(directory)
    except OSError:
        print('Error: Creating directory. ' + directory)

def search(dirname):
    img_list = []
    for (path, dir, files) in os.walk(dirname):
        for filename in files:
            ext = os.path.splitext(filename)[-1]
            if ext == '.jpg':
                img_list.append(path+'/'+filename)
    return img_list

classes = ['airplane', 'car', 'cat', 'dog', 'flower', 'fruit', 'motorbike', 'person']
img_list = []
for cls in classes:
    file_names = "8-multi-class_data/natural_images/" + cls
    img_list += search(file_names)

#img_list = search("8-multi-class_data/natural_images")

data_set = './8-multi-class_data/preprocessed_images/'

subdirs = ['train/', 'val/', 'test/']
labeldirs = ['airplane/', 'car/', 'cat/', 'dog/', 'flower/', 'fruit/', 'motorbike/', 'person/']
for sub in subdirs:
    for labelsub in labeldirs:
        dir_name = data_set + sub + labelsub
        # print(dir_name)
        createFolder(dir_name)

val_ratio_test = 0.2
val_ratio_val = 0.2
for i, img in enumerate(img_list):

    dst_dir = 'train/'
    if random() < val_ratio_test:
        dst_dir = 'test/'
    elif random() < val_ratio_test + val_ratio_val:
        dst_dir = 'val/'

    for cls in classes:
        a=img_list[i].split('/')[-1].find(cls)
        if img_list[i].split('/')[-1].find(cls) >= 0:
            dst = data_set + dst_dir + cls + '/'
            shutil.copy(img, dst)


