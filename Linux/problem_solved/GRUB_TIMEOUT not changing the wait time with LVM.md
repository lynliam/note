# [GRUB_TIMEOUT in /etc/default/grub not changing the wait time with LVM](https://askubuntu.com/questions/1123290/grub-timeout-in-etc-default-grub-not-changing-the-wait-time-with-lvm)



Source :  https://askubuntu.com/questions/1123290/grub-timeout-in-etc-default-grub-not-changing-the-wait-time-with-lvm



### Record :

Recently a patch has been merged fixing grub timeout menu to 30 seconds for UEFI systems with /boot on lvm or btrfs.

The reason for that in some cases a user can't access boot menu. `grub` can't write to lvm or btrfs.

If a boot fails, grub can't record it to LVM or btrfs, so there is an unlikely chance that you won't be able to get to grub menu for the safe mode, etc.

See [this bug report](https://bugs.launchpad.net/ubuntu/+source/grub2/+bug/1800722/) for more details.

If you look into `grub.cfg`, you'll see this:

```
if [ "${recordfail}" = 1 ] ; then
  set timeout=30
else
  if [ x$feature_timeout_style = xy ] ; then
    set timeout_style=hidden
    set timeout=0
  # Fallback hidden-timeout code in case the timeout_style feature is
  # unavailable.
  elif sleep --interruptible 0 ; then
    set timeout=0
  fi
fi
if [ $grub_platform = efi ]; then
  set timeout=30
  if [ x$feature_timeout_style = xy ] ; then
    set timeout_style=menu
  fi
fi
```

You can change it manually, but it will be reverted on `update-grub`.

This can be fixed by setting

```
GRUB_RECORDFAIL_TIMEOUT=0
```

in `/etc/default/grub` followed by `sudo update-grub` command.

if you are sure you'll be able to access UEFI settings. If not quite sure, set it to 5, or 10.

Another workaround would be to create a separate `/boot` partition outside of LVM or btrfs.