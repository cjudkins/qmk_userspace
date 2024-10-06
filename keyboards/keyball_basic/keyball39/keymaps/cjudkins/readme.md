To get QMK working on macOS, I had to run the following commands

```
git clone --recurse-submodules git@github.com:cjudkins/qmk_firmware.git -b holykeebs-master
brew install qmk/qmk/qmk
brew install arm-none-eabi-gcc
```

You may need to run commands like `git fetch` or `git submodule` to ensure that the repository is fully downloaded and up to date. When installing older versions of packages like the ones QMK relies on, brew sometimes fails to add them to $PATH. Look up how to use the ln command to fix this.

To compile my Keyball, run the command

`make keyball/keyball39:cjudkins`

To compile my Sweep, run the command

`make idank/sweeq:cjudkins:flash -e USER_NAME=idank`