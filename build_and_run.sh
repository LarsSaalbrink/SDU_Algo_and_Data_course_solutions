# Get subfolder name from first argument if available, else error
if [ -z "$1" ]
  then
    echo -e "\n!!!No folder supplied!!!\n"
    exit 1
fi
SUBFOLDER=$1

# if second argument is "clean", then delete "out" folder
if [ "$2" = "clean" ]
  then
    echo -e "--------------------Deleting build folder--------------------"
    rm -rf $SUBFOLDER/out
    echo -e "\nDone deleteing build folder!\n"
fi

# If subfolder has no folder "out", create fresh build system with "cmake -S . -B out/"
if [ ! -d "$SUBFOLDER/out" ] 
  then
    echo -e "--------------------Creating build folder--------------------"
    cmake -S $SUBFOLDER -B $SUBFOLDER/out
    echo -e "\nDone creating buildfolder!\n"
fi

# Build with command "make -C out/"
echo -e "--------------------Building--------------------"
make -C $SUBFOLDER/out
echo -e "\nDone building!\n"

# Run with command "./out/main"
echo -e "--------------------Running--------------------"
$SUBFOLDER/out/main
echo -e "\nDone running code!\n"

# When done running, call "gprof out/main > analysis.txt"
echo -e "--------------------Updating profiling analysis--------------------"
gprof $SUBFOLDER/out/main > $SUBFOLDER/analysis.txt
echo -e "\nAll done!\n"