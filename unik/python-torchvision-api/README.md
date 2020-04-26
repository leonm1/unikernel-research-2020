# Unik Python Torchvision API example

This example explores the process of executing a unikernel to perform torchvision/PyTorch image classification using Python and the rumprun unikernel, aided by Unik. This folder also contains a Nanos Ops `config.json` file which could be used to build the application with that build tool instead.

The Python code was adapted from github.com/avinassh/pytorch-flask-api.

Using Unik, the image never finishes booting, which is possibly do to
https://github.com/solo-io/unik/issues/84.

```sh
# Download the example ML model API (already included in this folder)
# git clone https://github.com/avinassh/pytorch-flask-api torchvision-api

# Write the unik manifest to the repo folder
echo 'main_file: app.py' > manifest.yaml

# Install dependencies to local directory (rather than system directory)
python3 -m venv env
pip install flask torchvision

# Ensure unik daemon is running. If not, run the following steps:
sudo systemctl start docker # Start docker if not already running
sudo modprobe loop # Load the loop network device, for the unik daemon
unik daemon

# (Destructive!) Delete existing image
unik rmi --force --image myImage

# The unik daemon is now running. Continue in another terminal window.
unik build --args '-m flask_main' --name myImage --path ./ --base rump --language python --provider virtualbox # This step takes a long time (a couple minutes)

# Run the kernel
unik run --instanceName myInstance --imageName myImage --env FLASK_APP=hello.py --env FLASK_ENV=production --env PATH=/env/bin --env VIRTUAL_ENV=/env

# Get the instance IP
unik instances
```

## Useful links

[Pytorch docs](https://github.com/pytorch/pytorch)

[Writing a Flask Unikernel with Rump Kernel](https://github.com/rumpkernel/wiki/wiki/Packages:-python3:-A-Flask-Unikernel)

[Unik getting started with Python3](https://github.com/solo-io/unik/blob/master/docs/getting_started_python3.md)

[Pytorch Flask API](https://github.com/avinassh/pytorch-flask-api)

[Tensorflow ResNet Guide](https://missinglink.ai/guides/tensorflow/tensorflow-resnet-building-training-scaling-residual-networks-tensorflow/)

[TensorFlow ResNet GitHub](https://github.com/tensorflow/models/tree/master/official/vision/image_classification)
