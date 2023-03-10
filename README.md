# Pixel-Player

## Description 

Pixel Player takes an image from your computer (file path specified by you) and prints it out as ASCII art. The image is turned into grayscale, and then the dithered image is turned into ASCII art by assigning each gray tone to a different character. Then the ASCII art is printed onto the terminal. 

This program only loads jpgs and pngs. If you try to load any other image type, the program will crash.

## How to run code

### Cloning the Repository
First, clone this directory onto your computer. To do this, click the green "code" button at the top of the screen. From there, either copy the SSH link or the HTTPS link. Then, in your terminal, run 
  git clone [copy link here].
  
  Once the repository is fully loaded up. Run the following lines of code in your terminal.
  ```
  mkdir build
  cd build/
  cmake ..
  make
  ./src/main
  ```
  The program will ask you for the file path of the image. Enter it. All preloaded images are stored in the /src/img folder. To find the file path run the following line in of the folder of image:
  ```
  readlink -f name_of_file.filetype
  ```
  
## Dependencies

## Demos

