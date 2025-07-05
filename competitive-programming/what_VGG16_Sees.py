import matplotlib.pyplot as plt
import numpy as np
from tensorflow.keras.applications import VGG16
from tensorflow.keras.models import Model
import cv2

def main():
	img_set = prepare_image()
	
	gray_img = img_set[1]
	#manual_kernel_convolution(gray_img)
	
	rgb_img = img_set[0]
	what_CNN_sees(rgb_img)
	
def manual_kernel_convolution(img):
	#--- Get manually-decided kernels
	kernel_set = define_kernel()
	
	#--- Convolution
	conv_img_set = [img]
	n = len(kernel_set)
	for i in range(n):
		conv_img = cv2.filter2D(img_set[1], ddepth = -1, kernel = kernel_set[i])
		conv_img_set.append(conv_img)

	#--- Display convolved image
	title_set = ['Grayscale', 'Horizontal Convolution', 'Vertical Convolution', 'Left-Diagonal Convolution', 'Right-Diagonal Convolution']
	display_imgs(conv_img_set, title_set, row = 2, col = 3)
	
def what_CNN_sees(rgb_img):
	#--- Load a pre-trained CNN
	vgg16 = VGG16(weights = 'imagenet', include_top = False)
	vgg16.summary()

	#--- Build a dummy model with layers until the 1st convolutional layer of 1st Conv-Block
	model = Model(vgg16.inputs, vgg16.get_layer('block3_conv1').output)
	model.summary()

	#--- Turn 3D RGB image 4D data to fulfill the requirements of keras' convolutional layers
	img3D = np.expand_dims(rgb_img, axis = 0)

	#--- Predict the output of the dummy model
	internal_img = model.predict(img3D)

	#--- Display what dummy model sees
	img_set = [rgb_img]
	title_set = ['Input RGB Image']
	for i in range(5):
		title_set.append('FeatureMap-' + str(i+1))
		img_set.append(internal_img[0, :, :, i])
	display_imgs(img_set, title_set, row = 2, col = 3)
	
def define_kernel():
	#--- Define 2D kernels
	horizontal_sobel_kernel= np.array([[-1, -2, -1], [0, 0, 0], [1, 2, 1]]).astype(np.int8)
	vertical_sobel_kernel = np.array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]]).astype(np.int8)
	left_diagonal_sobel_kernel = np.array([[0, 1, 2], [-1, 0, 1], [-2, -1, 0]]).astype(np.int8)
	right_diagonal_sobel_kernel = np.array([[-2, -1, 0], [-1, 0, 1], [0, 1, 2]]).astype(np.int8)

	#--- Display kernels
	kernel_set = [horizontal_sobel_kernel, vertical_sobel_kernel, left_diagonal_sobel_kernel, right_diagonal_sobel_kernel]
	title_set = ['Horizontal Kernel', 'Vertical Kernel', 'Left-Diagonal Kernel', 'Right-Diagonal Kernel']
	display_imgs(kernel_set, title_set, row = 2, col = 2)
	
	return kernel_set
	
def prepare_image():
	#--- Load an image from the Goggle Drive
	img_path = '/home/bibrity/CSE_Courses/DNN_2025/lotus.jpg' 
	rgb_img = plt.imread(img_path)
	print(rgb_img.shape)

	#--- Turn RGB image into a grayscale image
	gray_img = cv2.cvtColor(rgb_img, cv2.COLOR_RGB2GRAY)
	print(gray_img.shape)

	#--- Display loaded image
	img_set = [rgb_img, gray_img]
	title_set = ['RGB', 'Grayscale']
	display_imgs(img_set, title_set, row = 1, col = 2)
	
	return img_set

def display_imgs(img_set, title_set = '', row = 1, col = 1):
	n = len(img_set)
	plt.rcParams.update({'font.size': 20})
	plt.figure(figsize = (20, 20))
	for i in range(n):
		plt.subplot(row, col, i+1)
		if (title_set != ''):
			plt.title(title_set[i])
		if (len(img_set[i].shape) == 2):
			plt.imshow(img_set[i], cmap = 'gray')
		else:
			plt.imshow(img_set[i])
		plt.axis('off')
	plt.show()
	plt.close()

if __name__ == "__main__":
	main()