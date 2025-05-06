# news ticker

This is to mimic a news ticker, sometimes called a crawler or slide.

To compile, execute the following commands in the terminal:  
```bash
# Check out the library.
$ git clone https://github.com/fynnwilliam/news_ticker.git
# Go to the library root directory
$ cd news_ticker
# Make a build directory to place the build output.
$ cmake -E make_directory "build"
# Generate build system files with cmake.
$ cmake -DCMAKE_BUILD_TYPE=Release -S . -B "build"
# Build the library.
$ cmake --build "build" --config Release
# Optional - Go to the build directory to run the app
$ cd build
```
  
and to run the program, you may pass arguments directly to the binary

`$ ./slide message to be displayed`
 
 Kindly replace __*message to be displayed*__ with  the actual message you want to show.
or run it with no arguments to display the default message

`$ ./slide`