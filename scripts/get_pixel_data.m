image = imread(dir('*.jpg').name);
image = (image(:,:,1) + image(:,:,2) + image(:,:,3))/3;
writematrix(image, sprintf('image_1.txt'));
