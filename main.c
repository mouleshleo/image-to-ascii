#include <stdio.h>
#include <string.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void strrev(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}


  int main(int argc,char *argv[]) {
    char chars[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,";
    strrev(chars);
    int length = strlen(chars);
    
  int width,height,pixelSize;
  unsigned char *imageData = stbi_load(argv[1],&width,&height,&pixelSize, 0);
  if (imageData) {
    unsigned char *pixels = imageData;
    for (int i = 0;i < height;i++) {
      for (int j = 0;j < width;j++) {
        unsigned char R = *pixels++;
        unsigned char G = *pixels++;
        unsigned char B = *pixels++;
        if (pixelSize >= 4) {
        unsigned char A = *pixels++;
        }
        float avg = (R + G + B)/3.0f;
        int charIndex = (int)(length * (avg / 225.0f));
        putchar(chars[charIndex]);
      }

      putchar('\n');
    }
  } else {
    printf("IMAGE FAILED TO LOAD: %s\n",argv[1]);
  }
  
  return 0;
}



