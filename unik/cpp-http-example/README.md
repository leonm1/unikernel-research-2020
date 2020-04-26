# Unik C++ HTTP Endpoint Example

This example demonstrates the basic operation of an HTTP endpoint packaged into an IncludeOS unikernel by unik. This example requires VirtualBox and docker, as well as the unik daemon.

To run the example, please install the [unik daemon](https://github.com/solo-io/unik/) and follow the commands below:

```sh
sudo systemctl start docker # If not already running
sudo modprobe loop # Required for the build step

unik daemon --debug

# IN ANOTHER TERMINAL
unik target --host localhost
unik rmi --force --image myImage # Clean up from any previous attempts
unik build --name myImage --path ./ --base includeos --language cpp --provider virtualbox # Requires virtualbox
unik run --instanceName myInstance --imageName myImage

# See the image size itself
ll ~/.unik/virtualbox/images/myImage/boot.vmdk

# For comparison to a docker image
sudo docker run -p 80:80 -it --rm strm/helloworld-http
```
