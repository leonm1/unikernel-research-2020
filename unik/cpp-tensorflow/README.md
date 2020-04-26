# Unik C++ Tensorflow Example

This example attempts to build a simple program to print the version of tensorflow accessed by the system, but because Tensorflow cannot be statically linked at this time, it will fail at runtime as the library is unable to be loaded in the IncludeOS environment.

The example requires [Unik](https://github.com/solo-io/unik/) to be installed, as well as libtensorflow. The Makefile looks for tensorflow include files in /tensorflow, so attempts to build this program on your local machine should change this value to where the Tensorflow include files are kept on your machine. If tensorflow is installed to /tensorflow/include and /tensorflow/lib, LD_LIBRARY_PATH must be set to run the application on your local machine.

The following commands will build, but fail to run, the IncludeOS unikernel to print the version of Tensorflow linked in:

```sh
sudo systemctl start docker
sudo modprobe loop

unik daemon --debug

# IN ANOTHER TERMINAL
unik target --host localhost
unik rmi --force --image myImage # Clean up from any previous attempts
unik build --name myImage --path ./ --base includeos --language cpp --provider virtualbox
unik run --instanceName myInstance --imageName myImage

# See the image size itself
ll ~/.unik/virtualbox/images/myImage/boot.vmdk

# For comparison
sudo docker run -p 80:80 -it --rm strm/helloworld-http
```
