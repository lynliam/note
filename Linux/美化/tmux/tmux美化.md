# tmux美化



## 1. 安装插件管理tmux

```shell
#  https://github.com/tmux-plugins/tpm
git clone https://github.com/tmux-plugins/tpm ~/.tmux/plugins/tpm

```

```shell
#  Put this at the bottom of ~/.tmux.conf ($XDG_CONFIG_HOME/tmux/tmux.conf works too):

# List of plugins
set -g @plugin 'tmux-plugins/tpm'
set -g @plugin 'tmux-plugins/tmux-sensible'

# Other examples:
# set -g @plugin 'github_username/plugin_name'
# set -g @plugin 'github_username/plugin_name#branch'
# set -g @plugin 'git@github.com:user/plugin'
# set -g @plugin 'git@bitbucket.com:user/plugin'

# Initialize TMUX plugin manager (keep this line at the very bottom of tmux.conf)
run '~/.tmux/plugins/tpm/tpm'
```

```shell
#   Reload TMUX environment so TPM is sourced:

# type this in terminal if tmux is already running
tmux source ~/.tmux.conf
```



## 安装主题：

```shell
#   https://draculatheme.com/tmux
```

### Install using [tpm](https://github.com/tmux-plugins/tpm)

If you are a tpm user, you can install the theme and keep up to date by adding the following to your .tmux.conf file:

```shell
set -g @plugin 'dracula/tmux'
```

### Activating theme

1. Make sure  `run -b '~/.tmux/plugins/tpm/tpm'` is at the bottom of your .tmux.conf
2. Run tmux
3. Use the tpm install command: `prefix + I` (default prefix is ctrl+b)



### Configuration

```shell
# available plugins: battery, cpu-usage, git, gpu-usage, ram-usage, network, network-bandwidth, network-ping, attached-clients, network-vpn, weather, time, spotify-tui, kubernetes-context

set -g @dracula-plugins "cpu-usage gpu-usage ram-usage"

# available colors: white, gray, dark_gray, light_purple, dark_purple, cyan, green, orange, red, pink, yellow
# set -g @dracula-[plugin-name]-colors "[background] [foreground]"
set -g @dracula-cpu-usage-colors "pink dark_gray"

```





#### Status bar options

Enable powerline symbols

```
set -g @dracula-show-powerline true
```

Switch powerline symbols

```
# for left
set -g @dracula-show-left-sep 

# for right symbol (can set any symbol you like as seperator)
set -g @dracula-show-right-sep 
```

Enable window flags

```
set -g @dracula-show-flags true
```

Adjust the refresh rate for the status bar

```
# the default is 5, it can accept any number
set -g @dracula-refresh-rate 5
```

Switch the left smiley icon

```
# it can accept `session`, `smiley`, `window`, or any character.
set -g @dracula-show-left-icon session
```

Add padding to the left smiley icon

```
# default is 1, it can accept any number and 0 disables padding.
set -g @dracula-left-icon-padding 1
```

Enable high contrast pane border

```
set -g @dracula-border-contrast true
```

Hide empty plugins

```
set -g @dracula-show-empty-plugins false
```

#### cpu-usage options

Customize label

```
set -g @dracula-cpu-usage-label "CPU"
```

Show system load average instead of CPU usage percentage (default)

```
set -g @dracula-cpu-display-load true
```

CPU usage percentage (default) - in percentage (output: %) Load average – is the average system load calculated over a given period of time of 1, 5 and 15 minutes (output: x.x x.x x.x)

#### battery options

Customize label

```
set -g @dracula-battery-label "Battery"
```

#### gpu-usage options

Note, currently only the Linux NVIDIA Proprietary drivers are  supported. Nouveau and AMD Graphics Cards support are still under  development.

Customize label

```
set -g @dracula-gpu-usage-label "GPU"
```

#### ram-usage options

Customize label

```
set -g @dracula-ram-usage-label "RAM"
```

#### network-bandwidth

You can configure which network interface you want to view the bandwidth, Displaying of the interface name, The interval between each bandwidth update. The most common interfaces name are `eth0` for a wired connection and `wlan0` for a wireless connection.

```
set -g @dracula-network-bandwidth eth0
set -g @dracula-network-bandwidth-interval 0
set -g @dracula-network-bandwidth-show-interface true
```

#### network-ping options

You can configure which server (hostname, IP) you want to ping and at which rate (in seconds). Default is google.com at every 5 seconds.

```
set -g @dracula-ping-server "google.com"
set -g @dracula-ping-rate 5
```

#### time options

Disable timezone

```
set -g @dracula-show-timezone false
```

Swap date to day/month

```
set -g @dracula-day-month true
```

Enable military time

```
set -g @dracula-military-time true
```

#### git options

Hide details of git changes

```
set -g @dracula-git-disable-status true
```

Set symbol to use for when branch is up to date with HEAD

```
# default is ✓. Avoid using non unicode characters that bash uses like $, * and !
set -g @dracula-git-show-current-symbol ✓
```

Set symbol to use for when branch diverges from HEAD

```
# default is unicode !. Avoid bash special characters
set -g @dracula-git-show-diff-symbol !
```

Set symbol or message to use when the current pane has no git repo

```
# default is unicode no message
set -g @dracula-git-no-repo-message ""
```

Hide untracked files from being displayed as local changes

```
# default is false
set -g @dracula-git-no-untracked-files true
```

Show remote tracking branch together with diverge/sync state

```
# default is false
set -g @dracula-git-show-remote-status true
```

#### weather options

Switch from default fahrenheit to celsius

```
set -g @dracula-show-fahrenheit false
```

Set your location manually

```
set -g @dracula-fixed-location "Some City"
```

Hide your location

```
set -g @dracula-show-location false
```

#### attached-clients options

Set the minimum number of clients to show (otherwise, show nothing)

```
set -g @dracula-clients-minimum 1
```

Set the label when there is one client, or more than one client

```
set -g @dracula-clients-singular client
set -g @dracula-clients-plural clients
```



## 2. tmux 快捷键

