export THEOS_DEVICE_IP = 127.0.0.1 
export THEOS_DEVICE_PORT = 10010

INSTALL_TARGET_PROCESSES = SpringBoard

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = WeChatHook

// WeChatHook_FILES = src/Tweak.x src/*.m src/xxx/*m 
WeChatHook_FILES = src/Tweak.x src/*.m
WeChatHook_CFLAGS = -fobjc-arc

include $(THEOS_MAKE_PATH)/tweak.mk
