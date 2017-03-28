echo "Install Pcf libraries version 0.2.0, copyright GAMMA Soft, 2017"
echo ""

rm  -r Build
sudo mkdir /usr/local/cmake
sudo chmod 777 /usr/local/cmake
mkdir -p Build/Examples
mkdir -p Build/ThirdParties

brew update
brew upgrade
brew install cmake
brew install curl
brew install doxygen
brew install jpeg
brew install libpng
brew install zlib

cd Build/ThirdParties
cmake -G "Xcode" ../../ThirdParties
xcodebuild -target install -configuration Debug
xcodebuild -target install -configuration Release

cd ..
cmake -G "Xcode" ..
xcodebuild -target documentation -configuration Debug
open Help/html/index.html
xcodebuild -target install -configuration Debug
xcodebuild -target install -configuration Release

cd Examples
cmake -G "Xcode" ../../Examples
#xcodebuild -target ALL_BUILD -configuration Release
open Examples.xcodeproj
cd ../..
