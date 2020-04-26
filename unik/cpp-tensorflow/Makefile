#################################################
#          IncludeOS SERVICE makefile           #
#################################################

# The name of your service
SERVICE = IncludeOS_service
SERVICE_NAME = My IncludeOS Service

# Your service parts
FILES = hello_from_tf.c

# Your disk image
DISK=

# Add networking driver
DRIVERS=virtionet

# Your own include-path
LOCAL_INCLUDES=/tensorflow/include

PLATFORM=unik

# IncludeOS location
ifndef INCLUDEOS_INSTALL
INCLUDEOS_INSTALL=$(HOME)/IncludeOS_install
endif

# Include the installed seed makefile
include $(INCLUDEOS_INSTALL)/Makeseed
