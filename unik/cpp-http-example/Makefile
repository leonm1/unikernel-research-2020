#################################################
#          IncludeOS SERVICE makefile           #
#################################################

# The name of the service
SERVICE = IncludeOS_service
SERVICE_NAME = My IncludeOS Service

# Your service parts
FILES = service.cpp

# Your disk image
DISK=

# Add networking driver
DRIVERS=virtionet

# Your own include-path
LOCAL_INCLUDES=

PLATFORM=unik

# IncludeOS location
ifndef INCLUDEOS_INSTALL
INCLUDEOS_INSTALL=$(HOME)/IncludeOS_install
endif

# Include the installed seed makefile
include $(INCLUDEOS_INSTALL)/Makeseed
