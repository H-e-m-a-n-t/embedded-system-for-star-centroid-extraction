
pixel_size = 0.0000022;
length = 176;
breadth = 144;
image_centre_x = length/2;
image_centre_y = breadth/2;

text = readlines('rga/output.txt');
text = text(1:height(text)-1);

num_of_centroids = (height(text))/3;

output = str2double(reshape(text, 3, num_of_centroids));
output = round(output.*[1;1/pixel_size;-1/(pixel_size)]); 
output_final = output + [0; image_centre_x; image_centre_y]; 

image = imread(dir('*.jpg').name);
image = (image(:,:,1) + image(:,:,2) + image(:,:,3))/3;
original_image = image;

annotated_image = insertMarker(original_image, [output_final(2:3,:)'], 'o', 'size', 1);

figure
subplot(1,2,1)
imshow(original_image)
subplot(1,2,2)
imshow(annotated_image)
