# Bad Apple !! Played on GRUB
Bad Apple !! But it's on GRUB (2.06 but AFAIK, it should work on older versions).
[Link to the video](https://www.youtube.com/watch?v=zBhlu9lod6U)

## What's GRUB ?
"GNU GRUB (short for GNU GRand Unified Bootloader, commonly referred to as GRUB) is a boot loader package from the GNU Project. GRUB is the reference implementation of the Free Software Foundation's Multiboot Specification, which provides a user the choice to boot one of multiple operating systems installed on a computer or select a specific kernel configuration available on a particular operating system's partitions." [Wikipedia](https://en.wikipedia.org/wiki/GNU_GRUB)

Other useful resources, like documentation, [here](https://www.gnu.org/software/grub/index.html).

## How ?
Every frame of the video `Bad Apple !!` is saved as a text file in which if the pixel is white, a ` ` is written and if it is black, a `#` is written.
The C file in this repository can be used to generate these frames.

GRUB will simply show the content of each file one by one using the `cat` command quickly enough to give the illusion of motion. I added the script in a `menuentry` for clarity.

## Why is it challenging ?
The main problem with the scripting language of GRUB is ... the lack of support of arithmetic. So I had to make it possible without additions, which can be useful for doing a loop, for example. The solution I came up with is using `variable expansion`. We have around 5000 files, all named after their frame number so we will have 4 variables each representing a power of 10. The concatenation of each variable can be used to show a specific frame.

## What did you change for the video ?
First of all, I added the music [Bad Apple !!](https://www.youtube.com/watch?v=FtutLA63Cp8) on top of my record as this script does not include sound.
I also only showed the frames ending with the numbers 0, 3 and 7 to have a timing similar to the real one (I only had to put the recorded file at 95% to have a result similar to the first video).

## Can we add sound ?
It is technically possible to add sound between two frames but as each task is done sequentially, one would have to reduce the number of frames to keep a correct framerate as sound in GRUB takes some time. The way of generating the config file would also not be the same, the best answer I can come up with is not using `variable expansion` and instead programmatically generate a big configuration file with each filename and sound (in the GRUB format).

## What other things have you tried ?
GRUB can show image files as a background, so I tried to replace the `cat` command with backgrounds. Unfortunately due to the way GRUB handles I/O and backgrounds, this just cause the script to freeze a long time and show the last background.

I tried to put every frame in one big text file and have the scroll do the illusion of motion, but it didn't work.

I also tried to increase the speed by using a SSD but the results were even worse.
