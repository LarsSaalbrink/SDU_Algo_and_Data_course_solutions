Commands to use this folder:
    Generate build files into folder "out" with CMake:
        "cmake -S . -B out/"
        
        You can define which build system generator to use like this:
        (Default is "Make", replaced with "Ninja" here)
        	"cmake -S Ninja . -B out/"
        

    Build the files inside the folder "out":
        "make -C out/"

    Run the code by calling executable, name defined in upper CMakeLists.txt as "main" (Done through linux as file built is not an exe):
        "./out/main"


Running build system on WSL (Linux in windows) requires:
	-"sudo apt-get update"
	-"sudo apt-get install build-essential"
	-"sudo apt install ninja-build"       
	-"sudo apt install cmake"

	