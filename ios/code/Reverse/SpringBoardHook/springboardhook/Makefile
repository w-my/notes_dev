export THEOS_DEVICE_IP = 127.0.0.1 
export THEOS_DEVICE_PORT = 10010

INSTALL_TARGET_PROCESSES = SpringBoard

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = springboardhook

springboardhook_FILES = Tweak.x
springboardhook_CFLAGS = -fobjc-arc

include $(THEOS_MAKE_PATH)/tweak.mk
