<h1 align = "center"> Pixel Player </h1>


<p align="center">
  <img src="Figures/banner.png"  />
</p>

<p align = "center">
Use C to print any .jpg or .png image into your terminal as ASCII art!
</p>

## Table of Contents  
[What does this code do?](#what-does-this-code-do) 

[Structure Overview](#structure-overview)

[How to run the code](#how-to-run-the-code)

## What does this code do?

This code takes a string representing the file path to either a .jpg or .png image, loads it as a character array as long as the pixel width*height, and then converts it to an array of arrays, which represents the grayscaled image. At this point, the array is looped through and the grayscale values are replaced with their corresponding ASCII art, depending on how dark or light the image needs to be. Note that this code will load only the grayscale values of an image so it does not matter how many layers the image has. Between the image loading and ASCII generation, it is also resized to the user's terminal dimensions so that it is printed properly.

<p align="center">
  <img src="Figures/Code Run Steps.png"  />
</p>

Q: Why does this code load the image as a character array?

A: This is because our code relies on STB_image and STB_image_resize libraries to load and resize our code both of which use character arrays to represent the image.

Q: But aren't images arrays of integers ranging from 0 to 255, why chars?

A: Well it is because a char is actually just an integer ranging from 0 to 255, and a singular array is just as if we combined all of the rows of an array of arrays into one really long array.

Q: What is ASCII?

A: ASCII is an abbreviation for the American Standard Code for Information Interchange. In practical terms, ASCII is a common set of characters that are represented by a set number of integers.


## Structure Overview

Pixel player has two main libraries that are called in the main executabe when you run the program: photoprocess and dithering.

<p align="center">
  <img src="Figures/Code diagram (2).png"  />
</p>

### Photoprocess

This library handles three major functions:

* Receiving any user input from the terminal
* Attempting to load and resize the image to the user's terminal dimensions
* Clearing any heap memory allocated for the previous two steps

Both the user input and image loading plus resizing functionality relies on using malloc to pass their values between functions. As you can see in the overall diagram, photoprocess has it's own two dependencies: [stb_image](https://github.com/nothings/stb/blob/master/stb_image.h) and [stb_image_resize](https://github.com/nothings/stb/blob/master/stb_image_resize.h). Both of these are open source photo processing libraries available as header only libraries. This allows us to load them without needing any external downloads on the user's computer. 

The clearing memory function is mostly self explainable as it uses the free function to free the user input and then it loops through each array in the image array of arrays before freeing them as well.

### Dithering

The title of this library is tad misleading as our code does not use dithering in the traditional sense. Dithering is the action of spacing binary pixels to create the illusion of grey or other gradients. As our array is not binary but rather integers ranging from 0 to 255, we have to represent grey values with a different method. For this, we use a set of checks that convert certain ranges of pixel values to a corresponding ASCII character. For example, 255 represents an all white pixel, so this would correspond to a $ where as a pixel near 0 would most likely be represented by a blank value. This is made on the assumption that the user's terminal has a dark background and will look inverted on a white background. 


## How to run the code


### Cloning the Repository
First, clone this directory onto your computer. To do this, click the green "code" button at the top of the screen. From there, either copy the SSH link or the HTTPS link. Then, in your terminal, run 
  ```
  git clone copy_link_here
  ```
### Running the Code
Once the repository is fully loaded up. Run the following lines of code in your terminal. This assumes that you have C, GCC, and Cmake installed on your computer.
  ```
  mkdir build
  cd build/
  cmake ..
  make
  ./src/main
  ```
### Time to Print an Image!
The program will ask you for the file path of the image. Enter it. All preloaded images are stored in the /src/img folder. To find the file path of any image run the following line in the folder of the image:

  ```
  readlink -f name_of_file.filetype
  ```
Once you copy and paste the full file path, just hit enter and see your image come to life in ASCII glory! 

Quick tip: lower the text size of your terminal in order to receive a higher resolution output

## Contributors
This project was a collaboration between three Olin College of Engineering Students: Maya Cranor, Phillip Post, and Isabel de Luis. Special thanks to Steve Matsumoto for this help.
