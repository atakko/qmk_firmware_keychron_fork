# Keychron Q1 QMK V2, knob version
- Layout: ISO
- MCU: STM32L432
- Firmware (knob version): q1_iso_stm32l432_ec11
- [Keychron Q1 QMK V2](https://www.keychron.com/products/keychron-q1)
- [Reddit Keychron Q1 V2 Guide](https://www.reddit.com/r/Keychron/comments/va2agx/keychron_q1_v2_guide_how_do_i_changeadd_rgb/)


# What you need
- [QMK MSYS](https://github.com/qmk/qmk_distro_msys): In order for you to customize your keyboard, you need to compile your own firmware (don't worry, we will not make a firmware from scratch).
- [QMK Toolbox](https://github.com/qmk/qmk_toolbox): This is the last step, you will need it to flash the firmware into your keyboard.
- [Keychron firmware](https://github.com/Keychron/qmk_firmware/tree/playground/keyboards/keychron): To avoid making everything from scratch, you will need to grab a firmware that has everything in it. In this case we will need the Q1, so Right Click on that folder, Copy link address and then paste it here and download, we will need this directory later on.
- [WinCompose](https://github.com/samhocevar/wincompose): To get Unicode support in Windows, using UC_WINC mode


# Setup
    git clone https://github.com/Keychron/qmk_firmware.git
    git branch --set-upstream-to origin/master
    git checkout playground
    git checkout -b napa
    
    qmk setup
    qmk config user.keyboard=keychron/q1/q1_iso_stm32l432_ec11
    qmk config user.keymap=napa
    qmk new-keymap
    qmk compile
    
# Configurator

- [QMK configurator](https://config.qmk.fm/#/keychron/q1/rev_0102/LAYOUT_iso_83)

### To JSON 
    qmk c2json -kb keychron/q1/q1_iso_stm32l432_ec11 -km napa --no-cpp ./keyboards/keychron/q1/q1_iso_stm32l432_ec11/keymaps/napa/keymap.c

    

