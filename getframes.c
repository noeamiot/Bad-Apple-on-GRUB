// Derived from Ted Burke's work, you may have to update some values such as video path and resolution
#include <stdio.h>

int width = 207;
int heigth = 65;
unsigned char frame[65][207][3] = {0};
unsigned int n = 0; 

int main() {
	int x, y, count;
	 
	// Open an input pipe from ffmpeg and an output pipe to a second instance of ffmpeg
	FILE *pipein = popen("ffmpeg -i Bad_Apple-FtutLA63Cp8-nosound.mp4 -vf scale=207:65 -f image2pipe -vcodec rawvideo -pix_fmt rgb24 -", "r");

	// Process video frames
	while(1) {
		char name[50];
		sprintf(name, "frame%04d.txt", n); 
		FILE *fp =  fopen(name, "w+");
			// Read a frame from the input pipe into the buffer
			count = fread(frame, 1, heigth * width * 3, pipein);
			
			// If we didn't get a frame of video, we're probably at the end
			if (count != heigth * width * 3) break;
			
			// Process this frame
			for (y = 0 ; y < heigth ; ++y) {
				for (x = 0 ; x < width ; ++x) {
					if (frame[y][x][0] > 127 && frame[y][x][1] > 127 && frame[y][x][2] > 127)
						fputc('#', fp);
					else
						fputc(' ', fp);
				}
			fputc('\n', fp);
		}

		fclose(fp);
		n++;
	}
	 
	// Flush and close input and output pipes
	fflush(pipein);
	pclose(pipein);
}
