#pragma once

#include <windows.h>

class Bitmap{ 
	public: 
		Bitmap(){ //Constructor setting memory allowcation for size of bitmap file
			bits = NULL; memset(&bitmap, 0, sizeof(BITMAP));
		}; 
		~Bitmap(){  //Destructor
			clear(); 
		};
		bool loadFile(LPCSTR path){ //Loads a file passed upon its filepath 
			clear(); 
			HBITMAP hbitmap = (HBITMAP)::LoadImage(NULL, path, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE); //handle to the bitmap created to load in image
			if (!hbitmap){ 
				return false;  //If there is  no handle, get the object and pass into bitmap address 
			} ::GetObject(hbitmap, sizeof(BITMAP), &bitmap);
			bits = new unsigned char[bitmap.bmHeight * bitmap.bmWidthBytes ]; //Assign bits to variable
			HDC hdc = GetDC(NULL);  //Create a handle to device context
			BITMAPINFO bi = { 
				{sizeof(BITMAPINFOHEADER), bitmap.bmWidth, bitmap.bmHeight, bitmap.bmPlanes, bitmap.bmBitsPixel}  //Assign all the the various information to the bitmap info object
			}; ::GetDIBits( hdc, hbitmap, 0, bitmap.bmHeight, bits, &bi, DIB_RGB_COLORS );
			ReleaseDC( NULL, hdc ); ::DeleteObject( hbitmap );  //Release device context
			return true; 
		} 
		void clear(void) {  //Delete any allocated bits
			if(bits) { 
				delete bits; 
				bits = NULL; 
			} 
			memset(&bitmap, 0, sizeof(BITMAP)); //Reallocate to zero
		} 
		unsigned char* getBits(void) {  //Get bits
			return bits; 
		} 
		int getWidth(void){ //Get width in bits
			return bitmap.bmWidth; 
		}
		int getHeight(void){  //Get height in bits
			return bitmap.bmHeight; 
		}
		int getBitsPerPixel(void){ //Get bits per pixel
			return bitmap.bmBitsPixel; 
		}
		int getBitsPerLine(void){  //Get bits per line
			return bitmap.bmWidthBytes;
		}
	protected: 
		BITMAP bitmap; //Bitmap variable
		unsigned char *bits;  //Pointer to bit size
};