sudo yum update
sudo yum install clang

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

./scripts/install/install_redhat_gcc.sh
