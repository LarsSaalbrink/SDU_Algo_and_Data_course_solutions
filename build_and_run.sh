# Get subfolder name from first argument if available, else error
if [ -z "$1" ]
  then
    echo "!!!No folder supplied!!!"
    exit 1
fi
SUBFOLDER=$1

# if second argument is "clean", then delete "out" folder
if [ "$2" = "clean" ]
  then
    echo "--------------------Deleting build folder--------------------"
    rm -rf $SUBFOLDER/out
    echo "Done deleteing build folder!"
fi

# If subfolder has no folder "out", create fresh build system with "cmake -S . -B out/"
if [ ! -d "$SUBFOLDER/out" ] 
  then
    echo "--------------------Creating build folder--------------------"
    cmake -S $SUBFOLDER -B $SUBFOLDER/out
    echo "Done creating buildfolder!"
fi

# Build with command "make -C out/"
echo "--------------------Building--------------------"
make -C $SUBFOLDER/out
echo "Done building!"

# Run with command "./out/main"
echo "--------------------Running--------------------"
$SUBFOLDER/out/main
echo "Done running code!"

# When done running, call "gprof out/main > analysis.txt"
echo "--------------------Updating profiling analysis--------------------"
gprof $SUBFOLDER/out/main > $SUBFOLDER/analysis.txt
echo "All done!"