LTO_ENABLE          = yes    # Reduces the size of the compiled firmware
NKRO_ENABLE			= yes	 # Needs to be enabled to support sending FN on macOS 
CONSOLE_ENABLE      = no
MOUSEKEY_ENABLE     = yes    # Mouse keys
EXTRAKEY_ENABLE     = yes    # Audio and system keys
COMBO_ENABLE        = yes
KEY_OVERRIDE_ENABLE = yes
CAPS_WORD_ENABLE    = yes
TRI_LAYER_ENABLE    = yes

SRC += features/swapper.c
SRC += features/layer_lock.c

POINTING_DEVICE = cirque35
POINTING_DEVICE_POSITION = right