# Flopcoin Snap Packaging

Commands for building and uploading a Flopcoin Core Snap to the Snap Store. Anyone on amd64 (x86_64), arm64 (aarch64), or i386 (i686) should be able to build it themselves with these instructions. This would pull the official Flopcoin binaries from the releases page, verify them, and install them on a user's machine.

## Building Locally
```
sudo apt install snapd
sudo snap install --classic snapcraft
sudo snapcraft
```

### Installing Locally
```
snap install \*.snap --devmode
```

### To Upload to the Snap Store
```
snapcraft login
snapcraft register flopcoin-core
snapcraft upload \*.snap
sudo snap install flopcoin-core
```

### Usage
```
flopcoin-unofficial.cli # for flopcoin-cli
flopcoin-unofficial.d # for flopcoind
flopcoin-unofficial.qt # for flopcoin-qt
flopcoin-unofficial.test # for test_flopcoin
flopcoin-unofficial.tx # for flopcoin-tx
```

### Uninstalling
```
sudo snap remove flopcoin-unofficial
```