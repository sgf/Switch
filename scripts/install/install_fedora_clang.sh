sudo yum update
sudo yum install clang -y

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

./scripts/install/install_fedora_gcc.sh
